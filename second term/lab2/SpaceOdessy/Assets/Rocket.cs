using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class Rocket : MonoBehaviour
{
    public float radius = 75f; // радиус
                               //  RocketObj raketa = new RocketObj();
    RocketObj raketa;
    



    void Awake()
    {

        raketa = gameObject.AddComponent<RocketObj>();

        raketa.raketa= gameObject.GetComponent<Rigidbody2D>() as Rigidbody2D;

        raketa.thrust = 4f;
        raketa.boost = 0.4f;
        raketa.construct(raketa.thrust);


    }

    void Start()
    {
        
    }

    void FixedUpdate()
    {
        raketa.move(radius);
       

    }

}
