using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class Rocket : MonoBehaviour
{
    public static Rocket instanse;
    public bool starting = false;
    public float radius = 750f; // радиус
    RocketObj raketa;
    public GameObject simpleModuleOne, simpleModuleTwo;

     public void startSimulation(float _thrust, float _boost, float _fuelMainModule, float _fuelSimpleModules)
    {
        raketa.thrust = _thrust;
        raketa.boost = _boost;
        raketa.construct(raketa.thrust, _fuelMainModule, _fuelSimpleModules);
    }

    void Awake()
    {
        instanse = this;
        raketa = gameObject.AddComponent<RocketObj>();
        raketa.raketa= gameObject.GetComponent<Rigidbody2D>() as Rigidbody2D;
        simpleModuleOne = GameObject.Find("simpleModuleOne");
        simpleModuleTwo = GameObject.Find("simpleModuleTwo");
    }

    void Start()
    {
        
    }

    void FixedUpdate()
    {
        if (starting == true)
        {
            raketa.move(radius);
            //if (raketa.simpleModuleTwo.isNeed == false) { Destroy(simpleModuleTwo); }
           // if (raketa.simpleModuleOne.isNeed == false) { Destroy(simpleModuleOne); }
           
        }

        

    }

}
