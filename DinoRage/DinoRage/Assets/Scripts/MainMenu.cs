using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using TMPro;

public class MainMenu : MonoBehaviour
{
    public GameObject bulletPrefab;
    public Transform firePoint;
    public Transform target;
    public TMP_Text playButton;
    public TMP_Text quitButton;
    public GameObject effectPrefab;
    private bool isPlaying;
    private GameObject bulletGO;
    private Vector3 dir;
    private float distanceThisFrame;

    private string SceneToLoad = "LVLMenu";

    private void Start()
    {
        isPlaying = false;
        Time.timeScale = 1f;
    }

    private void Update()
    {
        if (bulletGO != null)
        {
            dir = target.position - firePoint.position; ;
            distanceThisFrame = 70f * Time.deltaTime;
            if (dir.magnitude <= distanceThisFrame)
            {
                Destroy(bulletGO);
                return;
            }
            bulletGO.transform.Translate(dir.normalized * distanceThisFrame, Space.World);
        }
    }
    public void Play()
    {
        playButton.text = string.Empty;
        quitButton.text = string.Empty;
        isPlaying = true;
        StartCoroutine(Shoot());
    }

    public void Quit()
    {
        quitButton.text = string.Empty;
        playButton.text = string.Empty;
        isPlaying = false;
        StartCoroutine(Shoot());
    }

    IEnumerator Shoot()
    {
        bulletGO = Instantiate(bulletPrefab, firePoint.position, firePoint.rotation);

        GameObject shootEffect = Instantiate(effectPrefab, firePoint.position, firePoint.rotation);

        yield return new WaitForSeconds(0.7f);
        if (isPlaying)
        {
            SceneManager.LoadScene(SceneToLoad);
        }
        else Application.Quit();
    }
}