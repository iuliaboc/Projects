using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
public class CountDownTimer : MonoBehaviour
{
    float currentTime = 0f;
    float startingTime = 60f;

    [SerializeField] Text countdownText;

    void Start()
    {
        currentTime = startingTime;   
    }

    void Update()
    {
        currentTime -= 1 * Time.deltaTime;
        if (currentTime <= 0)
            SceneManager.LoadScene("GameOver");
        countdownText.text = currentTime.ToString("0");
      
    }
}
