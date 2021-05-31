using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HealthBar : MonoBehaviour
{
    public Slider slider;

    public void SetMaxHealth(int health)
    {
        slider.maxValue = health;
        slider.value = health; 
    }

    public void SetHealth(float health)
    {
        slider.value = health;
    }

    public float GetHealth()
    {
        return slider.value;
    }

    public void ApplyDamage()
    {
        slider.value -= 1;
        if (slider.value==0)
        {
            Application.LoadLevel("GameOver");
        }
    }
}
