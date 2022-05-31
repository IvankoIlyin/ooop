using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;


    public class RocketObj : MonoBehaviour

    {
        public MainRocketModule mainModule;
        public Rigidbody2D raketa;
        public float thrust;
         public float boost;
        public float angle = 0;
        public bool PositiononOrbit = false;
        
        public void construct( float _thrust)
    {
        mainModule = new MainRocketModule(raketa, 15f,_thrust , 1f, true, PositiononOrbit);
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
            raketa.rotation += 1f;
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


        public void move(float radius)
        {

            float currentRadius = Mathf.Sqrt((raketa.position.x * raketa.position.x) + (raketa.position.y * raketa.position.y));
            mainModule.ModuleLife();
             raketa.mass = mainModule.massOfModule;
        mainModule.PositiononOrbit = PositiononOrbit;
        mainModule.thrust = thrust;
        
        if (mainModule.canFly == false)
        {
            thrust = 0f;
            boost = 0f;
        }
        if (currentRadius <= radius / 2f && PositiononOrbit == false)
            {
                intoOrbit();
            }


            if (currentRadius >= radius / 2f && currentRadius <= radius && PositiononOrbit == false)
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
    void Segregation();
    void LifeModule(float fuel,bool canFly, bool PositiononOrbit);
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
        if (fuel == 0 || PositiononOrbit == true)
        {
            isNeed = false;
        }
        else if (fuel != 0 && PositiononOrbit == false)
        {
            isNeed = true;
        }

        return isNeed;
    }

    public float mass—onsumption(float fuel, float thrust, float massOfModule)
    {
        if (fuel >= 0)
        {
            massOfModule -= fuel * 0.0005f;
        }
        return massOfModule;
    }

    public float fuel—onsumption(float fuel, float thrust)
    {

        if (fuel >= 0)
        {
            fuel = fuel - thrust * 0.05f;
        }
        return fuel;

    }
    public void Segregation()
    {
       //do something animation for simple module
    }

    public void LifeModule(float fuel, bool isNeed, bool PositiononOrbit)
    {
        
        checkForSegregation( fuel,  isNeed,  PositiononOrbit);
        if (isNeed == false)
        {
            Segregation();
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
            fuel = fuel - thrust * 0.0005f;
        }
        return fuel;
        
    }

    public float mass—onsumption(float fuel, float thrust, float massOfModule)
    {
        if (fuel >= 0)
        {
            massOfModule -= fuel * 0.0005f;
        }
        return massOfModule;
    }

    public void Segregation()
    {
        //do something animation for main module
        //module.AddForce( new Vector2(-1f,0f));
        Debug.Log("dddd");
    }

    public void LifeModule(float fuel, bool canFly, bool PositiononOrbit)
    {
        
        checkForSegregation( fuel,  canFly,  PositiononOrbit);
        if (canFly == false)
        {
            Segregation();
           
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

    protected void Segregation()
    {
        moduleBehavior.Segregation();
    }

    protected void LifeModule(float fuel, float thrust, float massOfModule, bool canFly, bool PositiononOrbit)
    {
        moduleBehavior.LifeModule( fuel, canFly,  PositiononOrbit);
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

    public MainRocketModule(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _canFly, bool _PositiononOrbit)
    {
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule+_fuel;
        canFly = _canFly;
        PositiononOrbit = _PositiononOrbit;
        SetModuleBehavior(new MainModuleBehavior(module, _fuel, thrust, massOfModule, canFly, PositiononOrbit));
    }

    public MainRocketModule ShallowCopy()
    {
        return (MainRocketModule)this.MemberwiseClone();
    }
    public void ModuleLife()
    {
        LifeModule(fuel, thrust, massOfModule, canFly, PositiononOrbit);
        fuel =fuel—onsumption(fuel,thrust);
        canFly = checkForSegregation(fuel, canFly, PositiononOrbit);
        massOfModule = mass—onsumption(fuel, thrust, massOfModule);
        Debug.Log(fuel);
        
    }
}

    public class SimpleRocketModule : ModuleBase
    {
    public Rigidbody2D module;
    public float fuel;
    public float massOfModule;
    public bool isNeed=true;
    private float thrust;
    private bool PositiononOrbit=false;

    public SimpleRocketModule(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _isNeed, bool _PositiononOrbit)
    {
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule;
        isNeed = _isNeed;
        PositiononOrbit = _PositiononOrbit;
        SetModuleBehavior(new SimpleModuleBehavior(module, fuel, thrust, massOfModule, isNeed, PositiononOrbit));
    }

    public SimpleRocketModule ShallowCopy()
    {
        return (SimpleRocketModule)this.MemberwiseClone();
    }
    public void ModuleLife()
    {
       
        checkForSegregation(fuel, isNeed, PositiononOrbit);
        fuel—onsumption(fuel,thrust);
        //Debug.Log(fuel);    
        Segregation();
        LifeModule(fuel,thrust,massOfModule,isNeed,PositiononOrbit);
        
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