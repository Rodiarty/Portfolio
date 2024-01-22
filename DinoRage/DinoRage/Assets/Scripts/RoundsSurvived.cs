using TMPro;
using UnityEngine;

public class RoundsSurvived : MonoBehaviour
{
    public TMP_Text roundsText;

    void OnEnable()
    {
        roundsText.text = PlayerStats.Rounds.ToString();
    }
}
