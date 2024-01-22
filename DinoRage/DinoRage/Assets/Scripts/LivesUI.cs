using TMPro;
using UnityEngine;

public class LivesUI : MonoBehaviour
{
    public TMP_Text textLives;

    void Update()
    {
        textLives.text = "HP:  " + PlayerStats.Lives + "/20";
    }
}
