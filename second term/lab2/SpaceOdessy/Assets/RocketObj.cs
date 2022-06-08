using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;


    public class RocketObj : MonoBehaviour

    {
        public MainRocketModule mainModule;
        public SimpleRocketModule simpleModuleOne, simpleModuleTwo;
        public Rigidbody2D raketa;
        public float thrust;
        public float boost;
        public float angle = 0;
        public bool PositiononOrbit = false;
        
        public void construct( float _thrust, float _fuelMainModule, float _fuelSimpleModules)
    {
        mainModule = new MainRocketModule(raketa, _fuelMainModule, _thrust , 1f, true, PositiononOrbit,0);
        simpleModuleOne = new SimpleRocketModule(raketa, _fuelSimpleModules, _thrust, 1f, true, PositiononOrbit, 1);
        simpleModuleTwo = simpleModuleOne.ShallowCopy();
        simpleModuleTwo.order = 2;
        simpleModuleTwo.fuel = _fuelSimpleModules;

    }
        private void intoOrbit()
        {
        if (mainModule.canFly == true)
        {
            raketa.AddForce(transform.up * thrust);
           thrust += boost;
        }
        }

        private void toOrbit()
        {
        if (mainModule.canFly == true)
        {
            raketa.rotation += 0.3f;
            float angel = raketa.rotation * Mathf.Deg2Rad;
            raketa.AddForce(new Vector2(-thrust * Mathf.Sin(angel), thrust * Mathf.Cos(angel)), ForceMode2D.Force);
        }

        }

        private void onOrbit(float radius)
        {
            angle += Time.deltaTime; // ÏÂÌˇÂÚÒˇ ÔÎ‡‚ÌÓ ÁÌ‡˜ÂÌËÂ Û„Î‡
            raketa.gravityScale = 0;

            var x = Mathf.Cos(angle * 1f) * radius;
            var y = Mathf.Sin(angle * 1f) * radius;
            raketa.AddForce(transform.position = new Vector2(x, y));
            raketa.rotation += (2 * Mathf.PI * radius * 0.2f) / Mathf.Sqrt(x * x + y * y);

        }

        private void modulesLife()
    {
        raketa.mass = mainModule.massOfModule+simpleModuleOne.massOfModule+simpleModuleTwo.massOfModule;
        mainModule.PositiononOrbit = PositiononOrbit;
        simpleModuleOne.PositiononOrbit = PositiononOrbit;
        simpleModuleTwo.PositiononOrbit = PositiononOrbit;
        mainModule.thrust = thrust;
        simpleModuleOne.thrust = thrust;
        simpleModuleTwo.thrust = thrust;
        if (simpleModuleTwo.isNeed == true)
        {
            simpleModuleTwo.ModuleLife();
            Debug.Log("two"+" "+ simpleModuleTwo.fuel);
        }

        if (simpleModuleTwo.isNeed==false && simpleModuleOne.isNeed == true)
        {
            simpleModuleOne.ModuleLife();
            Debug.Log("one" + " " + simpleModuleOne.fuel);

        }

        if (simpleModuleOne.isNeed == false && mainModule.canFly==true)
        {
            mainModule.ModuleLife();
            Debug.Log("main" + " " + mainModule.fuel);
        }

    }
        public void move(float radius)
        {

            float currentRadius = Mathf.Sqrt((raketa.position.x * raketa.position.x) + (raketa.position.y * raketa.position.y));
            modulesLife();
        
            if (mainModule.canFly == false)
        {
            thrust = 0f;
            boost = 0f;
        }

            if (currentRadius <= radius / 2f && PositiononOrbit == false)
            {
                intoOrbit();
            }


            if (currentRadius >= radius / 2.5f && currentRadius <= radius && PositiononOrbit == false)
            {
                toOrbit();

            }

            if (currentRadius >= radius)
            {
                PositiononOrbit = true;
            }


            if (PositiononOrbit == true)
            {
                onOrbit(radius);
            }

        
        }


    }

    public interface ModuleBehavior
{
    bool checkForSegregation(float fuel, bool canFly, bool PositiononOrbit);
    float fuel—onsumption(float fuel, float thrust);
    float mass—onsumption(float fuel, float thrust, float massOfModule);
    void Segregation(int order);
    void LifeModule(float fuel,bool canFly, bool PositiononOrbit, int order);
}

    public class SimpleModuleBehavior: ModuleBehavior
{

    public SimpleModuleBehavior(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _isNeed, bool _PositiononOrbit)
    {/*
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule;
        isNeed = _isNeed;
        PositiononOrbit = _PositiononOrbit;*/
    }
  
    public bool checkForSegregation(float fuel, bool isNeed, bool PositiononOrbit)
    {
        if (fuel <= 0 || PositiononOrbit == true)
        {
            isNeed = false;
        }
        else if (fuel >= 0 && PositiononOrbit == false)
        {
            isNeed = true;
        }

        return isNeed;
    }

    public float mass—onsumption(float fuel, float thrust, float massOfModule)
    {
        if (fuel >= 0)
        {
            massOfModule -= fuel * 0.001f;
        }
        return massOfModule;
    }

    public float fuel—onsumption(float fuel, float thrust)
    {

        if (fuel >= 0)
        {
            fuel = fuel - thrust * 0.0004f;
        }
        return fuel;

    }
    public void Segregation(int order)
    {
      //  Debug.Log("module number " + order + " makes BOOOOM");
    }

    public void LifeModule(float fuel, bool isNeed, bool PositiononOrbit, int order)
    {
        
        checkForSegregation( fuel,  isNeed,  PositiononOrbit);
        if (isNeed == false)
        {
            Segregation(order);
        }

    }
}

    public class MainModuleBehavior: ModuleBehavior
{

    public MainModuleBehavior(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _canFly, bool _PositiononOrbit)
    {
      /*  module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule;
        canFly = _canFly;
        PositiononOrbit = _PositiononOrbit;*/
    }

    public bool checkForSegregation(float fuel, bool canFly, bool PositiononOrbit)
    {
        if (fuel <= 0 && PositiononOrbit==false)
        {
            canFly = false;
        }
        if (PositiononOrbit == true)
        {
            canFly = true;
        }

        return canFly;
    }

    public float fuel—onsumption(float fuel, float thrust)
    {
        if (fuel >= 0)
        {
            fuel = fuel - thrust * 0.0004f;
        }
        return fuel;
        
    }

    public float mass—onsumption(float fuel, float thrust, float massOfModule)
    {
        if (fuel >= 0)
        {
            massOfModule -= fuel * 0.01f;
        }
        return massOfModule;
    }

    public void Segregation(int order)
    {
       // Debug.Log("module number " + order + " makes BOOOOM");
    }

    public void LifeModule(float fuel, bool canFly, bool PositiononOrbit, int order)
    {
        
        checkForSegregation( fuel,  canFly,  PositiononOrbit);
        if (canFly == false)
        {
            Segregation(order);
           
        }

    }
}

    public abstract class ModuleBase : MonoBehaviour
{
    protected ModuleBehavior moduleBehavior;

    public void SetModuleBehavior(ModuleBehavior _moduleBehavior)
    {
        moduleBehavior = _moduleBehavior;
    }

    protected bool checkForSegregation(float fuel, bool canFly, bool PositiononOrbit)
    {
       canFly= moduleBehavior.checkForSegregation( fuel,  canFly,  PositiononOrbit);

        return canFly;
    }

    protected float fuel—onsumption(float fuel, float thrust)
    {
       fuel = moduleBehavior.fuel—onsumption( fuel,  thrust);
        
        return fuel;
    }

    protected float mass—onsumption(float fuel, float thrust, float massOfModule)
    {
        massOfModule = moduleBehavior.mass—onsumption(fuel, thrust, massOfModule);

        return massOfModule;
    }

    protected void Segregation(int order)
    {
        moduleBehavior.Segregation(order);
    }

    protected void LifeModule(float fuel, float thrust, float massOfModule, bool canFly, bool PositiononOrbit, int order)
    {
        moduleBehavior.LifeModule( fuel, canFly,  PositiononOrbit, order);
    }

}
    //Strategy


    public class MainRocketModule:ModuleBase
    {

    public Rigidbody2D module ;
    public float fuel;
    public float massOfModule;
    public bool mainModule;
    public bool canFly = true;
    public float thrust;
    public bool PositiononOrbit;
    public int order;

    public MainRocketModule(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _canFly, bool _PositiononOrbit,int _order)
    {
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule+_fuel;
        canFly = _canFly;
        PositiononOrbit = _PositiononOrbit;
        order = _order;
        SetModuleBehavior(new MainModuleBehavior(module, _fuel, thrust, massOfModule, canFly, PositiononOrbit));
    }

    public MainRocketModule ShallowCopy()
    {
        return (MainRocketModule)this.MemberwiseClone();
    }
    public void ModuleLife()
    {
        LifeModule(fuel, thrust, massOfModule, canFly, PositiononOrbit,order);
        fuel =fuel—onsumption(fuel,thrust);
        canFly = checkForSegregation(fuel, canFly, PositiononOrbit);
        massOfModule = mass—onsumption(fuel, thrust, massOfModule);
        
    }
}

    public class SimpleRocketModule : ModuleBase
    {
    public Rigidbody2D module;
    public float fuel;
    public float massOfModule;
    public bool isNeed=true;
    public float thrust;
    public int order;
    public bool PositiononOrbit=false;

    public SimpleRocketModule(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _isNeed, bool _PositiononOrbit, int _order)
    {
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule+_fuel;
        isNeed = _isNeed;
        PositiononOrbit = _PositiononOrbit;
        order = _order;
        SetModuleBehavior(new SimpleModuleBehavior(module, fuel, thrust, massOfModule, isNeed, PositiononOrbit));
    }

    public SimpleRocketModule ShallowCopy()
    {
        return (SimpleRocketModule)this.MemberwiseClone();
    }
    public void ModuleLife()
    {
       
       isNeed= checkForSegregation(fuel, isNeed, PositiononOrbit);
       fuel =   fuel—onsumption(fuel,thrust);
        massOfModule = mass—onsumption(fuel, thrust, massOfModule);
        LifeModule(fuel,thrust,massOfModule,isNeed,PositiononOrbit, order);
        
    }
}

  /*  public class RocketModule : RocketObj
    {
        public Rigidbody2D module;
        public float fuel;
        public float massOfModule;
        public bool mainModule;
        public bool isNeed;


        public RocketModule ShallowCopy()
        {
            return (RocketModule)this.MemberwiseClone();
        }


        public RocketModule(float fuel, float mass, bool mModule)
        {
            this.isNeed = true;
            this.fuel = fuel;
            this.mainModule = mModule;
            this.massOfModule = mass + fuel * 0.3f;
            module.mass = massOfModule;

        }

        private void checkForSegregation()
        {
            if (fuel == 0 || PositiononOrbit == true)
            {
                isNeed = false;
            }
            else if (fuel != 0 && PositiononOrbit == false)
            {
                isNeed = true;
            }
        }

        private void fuel—onsumption()
        {
            fuel -= thrust * 0.003f;
            module.mass -= fuel * 0.0005f;
        }

        private void Segregation()
        {
            Destroy(this.module);
        }

        public void LifeModule()
        {
            fuel—onsumption();
            checkForSegregation();
            if (mainModule != true && isNeed == false)
            {
                Segregation();
            }

        }


    }

*/