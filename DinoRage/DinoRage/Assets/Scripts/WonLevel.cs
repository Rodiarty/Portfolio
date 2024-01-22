using UnityEngine;
using UnityEngine.SceneManagement;

public class WonLevel : MonoBehaviour
{
    public string nextLevel = "Level02";
    public int levelToUnlock = 2;

    public void Menu()
    {
        PlayerPrefs.SetInt("levelReached", levelToUnlock);
        SceneManager.LoadScene("LVLMenu");
    }

    public void Continue()
    {
        PlayerPrefs.SetInt("levelReached", levelToUnlock);
        SceneManager.LoadScene(nextLevel);
    }
}
