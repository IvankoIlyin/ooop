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
       // GameObject gameObj = new GameObject("RocketObj");
        raketa = gameObject.AddComponent<RocketObj>();

        raketa.raketa= gameObject.GetComponent<Rigidbody2D>() as Rigidbody2D;
    }

    void Start()
    {
        raketa.thrust = 1f;


    }

    void FixedUpdate()
    {
        raketa.move(radius);
    }

}
