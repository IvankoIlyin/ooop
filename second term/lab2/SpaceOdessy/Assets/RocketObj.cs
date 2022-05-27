using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;


    public class RocketObj : MonoBehaviour

    {
        public MainRocketModule mainModule;
        public Rigidbody2D raketa;
        public float thrust;
        public float angle = 0;
        public bool PositiononOrbit = false;
        
        public void construct( float _thrust)
    {
        mainModule = new MainRocketModule(raketa, 200f,_thrust , 1f, true, PositiononOrbit);
        Debug.Log(mainModule.thrust);
    }
        private void intoOrbit()
        {
        if (mainModule.canFly == true)
        {
            raketa.AddForce(transform.up * thrust);
            thrust += 0.1f;
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
            angle += Time.deltaTime; // �������� ������ �������� ����
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
           // Debug.Log(mainModule.fuel);
             raketa.mass = mainModule.massOfModule;
 
        if (mainModule.canFly == false)
        {
            thrust = 0f;
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

    public class Modules
{
    MainRocketModule MainModule;
    SimpleRocketModule moduleOne, moduleTwo, moduleThrie;

}

    public interface ModuleBehavior
{
    void checkForSegregation();
    void fuel�onsumption();
    void Segregation();
    void LifeModule();
}

    public class SimpleModuleBehavior: ModuleBehavior
{

    private Rigidbody2D module;
    private float fuel;
    private float thrust;
    private float massOfModule;
    private bool isNeed;
    private bool PositiononOrbit;

    public SimpleModuleBehavior(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _isNeed, bool _PositiononOrbit)
    {
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule;
        isNeed = _isNeed;
        PositiononOrbit = _PositiononOrbit;
    }

    public void checkForSegregation()
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

    public void fuel�onsumption()
    {
        fuel -= thrust * 0.003f;
        module.mass -= fuel * 0.0005f;
    }

    public void Segregation()
    {
       //do something animation for simple module
    }

    public void LifeModule()
    {
        fuel�onsumption();
        checkForSegregation();
        if (isNeed == false)
        {
            Segregation();
        }

    }
}

    public class MainModuleBehavior: ModuleBehavior
{

    private Rigidbody2D module;
    private float fuel;
    private float thrust;
    private float massOfModule;
    private bool canFly=true;
    private bool PositiononOrbit;

    public MainModuleBehavior(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _canFly, bool _PositiononOrbit)
    {
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule;
        canFly = _canFly;
        PositiononOrbit = _PositiononOrbit;
    }

    public void checkForSegregation()
    {
        if (fuel == 0 || PositiononOrbit == false)
        {
            canFly = false;
          //  Debug.Log(canFly);
           /// Debug.Log(fuel);
        }
        else if (PositiononOrbit == true)
        {
            canFly = true;
        }
    }

    public void fuel�onsumption()
    {
      
            fuel = fuel - thrust * 2f;
            massOfModule -= fuel * 0.0005f;
        
    }

    public void Segregation()
    {
        //do something animation for main module
        //module.AddForce( new Vector2(-1f,0f));
        //Debug.Log("dddd");
    }

    public void LifeModule()
    {
        
        fuel�onsumption();
        checkForSegregation();
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

    protected void checkForSegregation()
    {
        moduleBehavior.checkForSegregation();
    }

    protected void fuel�onsumption()
    {
        moduleBehavior.fuel�onsumption();
    }

    protected void Segregation()
    {
        moduleBehavior.Segregation();
    }

    protected void LifeModule()
    {
        moduleBehavior.LifeModule();
    }

}
    //Strategy


    public class MainRocketModule:ModuleBase
    {
    public Rigidbody2D module;
    public float fuel;
    public float massOfModule;
    public bool mainModule;
    public bool canFly=true;
    public float thrust;
    public bool PositiononOrbit=false;

    public MainRocketModule(Rigidbody2D _module, float _fuel, float _thrust, float _massOfModule, bool _canFly, bool _PositiononOrbit)
    {
        module = _module;
        fuel = _fuel;
        thrust = _thrust;
        massOfModule = _massOfModule;
        canFly = _canFly;
        PositiononOrbit = _PositiononOrbit;
        SetModuleBehavior(new MainModuleBehavior(module, fuel, thrust, massOfModule, canFly, PositiononOrbit));
    }

    public MainRocketModule ShallowCopy()
    {
        return (MainRocketModule)this.MemberwiseClone();
    }
    public void ModuleLife()
    {
        fuel�onsumption();
        LifeModule();
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
    }

    public SimpleRocketModule ShallowCopy()
    {
        return (SimpleRocketModule)this.MemberwiseClone();
    }
    public void ModuleLife()
    {
        SetModuleBehavior(new SimpleModuleBehavior(module, fuel, thrust, massOfModule, isNeed, PositiononOrbit));
        checkForSegregation();
        fuel�onsumption();
        Segregation();
        LifeModule();
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

        private void fuel�onsumption()
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
            fuel�onsumption();
            checkForSegregation();
            if (mainModule != true && isNeed == false)
            {
                Segregation();
            }

        }


    }

*/