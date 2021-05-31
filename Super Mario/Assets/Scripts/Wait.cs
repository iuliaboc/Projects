using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Wait : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        ChangeToScene("Level2");
    }

    IEnumerator WaitBeforeShow()
    {
        if(SceneManager.GetSceneByName("Level0WaitingScene").name=="Level0WaitingScene")
        {
            yield return new WaitForSeconds(2);
        }
        yield return new WaitForSeconds(5);
    }

    public void ChangeToScene(string sceneToChangeTo)
    {
        if (SceneManager.GetSceneByName("Level0WaitingScene").name == "Level0WaitingScene")
        {
            StartCoroutine(DoChangeScene(sceneToChangeTo, 2f));
        }
        StartCoroutine(DoChangeScene(sceneToChangeTo, 6f));
    }
    IEnumerator DoChangeScene(string sceneToChangeTo, float delay)
    {
        yield return new WaitForSeconds(delay);
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
