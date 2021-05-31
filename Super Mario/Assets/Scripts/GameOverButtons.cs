using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameOverButtons : MonoBehaviour
{
    public void PlayGame()
    {
        SceneManager.LoadScene("Level0WaitingScene");
        ScoreCount.scoreValue = 0;
    }

    public void QuitGame()
    {
        Application.Quit();
    }

    public void Leaderboard()
    {
        SceneManager.LoadScene("Leaderboard");
    }

}
