using UnityEngine;

public class ShowInfo : MonoBehaviour
{
    public GameObject HistoryUI;
    public GameObject TutorUI;

    private void Start()
    {
        HistoryUI.SetActive(true);
        TutorUI.SetActive(false);
        Time.timeScale = 0f;
    }

    void Update()
    {
        if (HistoryUI.activeSelf && Input.GetKeyDown(KeyCode.Return))
        {
            HistoryUI.SetActive(false);
            TutorUI.SetActive(true);
        }
        if (TutorUI.activeSelf && Input.GetKeyDown(KeyCode.Space))
        {
            TutorUI.SetActive(false);
            Time.timeScale = 1f;
        }
    }
}
