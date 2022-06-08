using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
  private Transform rocketTransform;

    private void Start()
    {
        rocketTransform = GameObject.Find("Rocket").transform;
    }

    private void LateUpdate()
    {
        Vector3 temp = transform.position;
        temp.x = rocketTransform.position.x;
        temp.y = rocketTransform.position.y;
        transform.position = temp;
       
    }
}
