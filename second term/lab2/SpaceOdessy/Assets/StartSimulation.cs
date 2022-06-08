using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class StartSimulation : MonoBehaviour
{

    public InputField power;
    public InputField boost;
    public InputField fuel;
    private void GetAndStart()
    {
       
        Rocket.instanse.startSimulation(5f, 0.4f, 5f, 3f);
        Rocket.instanse.starting = true;
    }

    public void ReadStringInput()
    {
       
    }
   
}
