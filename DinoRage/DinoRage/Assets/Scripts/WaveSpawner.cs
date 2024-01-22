using System.Collections;
using TMPro;
using UnityEngine;

public class WaveSpawner : MonoBehaviour
{
    public Transform enemyPrefab;

    public Transform spawnPoint;

    public int waveCount;
   
    public float timeBetweenWaves = 5f;
    private float countdown = 2f;

    public GameManager gameManager;

    public TMP_Text waveCountdownText;

    private int waveIndex = 0;
    private int spawnedEnemy;
    Quaternion startRotation = new Quaternion();

    private void Start()
    {
        Time.timeScale = 1.0f;
        spawnedEnemy = 0;
        waveIndex = 0;
        Enemy.enemyDead = 0;
    }

    void Update()
    {
        if (waveIndex < waveCount)
        {
            if (countdown <= 0f)
            {
                StartCoroutine(SpawnWave());
                countdown = timeBetweenWaves;
            }

            countdown -= Time.deltaTime;

            countdown = Mathf.Clamp(countdown, 0f, Mathf.Infinity);
        if (waveCount==waveIndex) 
            {
                waveCountdownText.text = "0";
            }
        else waveCountdownText.text = string.Format("{0:F0}", countdown);
        }
        if (waveIndex == waveCount && spawnedEnemy == Enemy.enemyDead)
        {
            gameManager.WinLevel();
            enabled = false;
        }
    }


    IEnumerator SpawnWave()
    {
        waveIndex++;
        PlayerStats.Rounds++;

        for (int i = 0; i < waveIndex; i++)
        {
            SpawnEnemy();
            spawnedEnemy++;
            yield return new WaitForSeconds(1f);
        }
    }

    void SpawnEnemy()
    {
        Instantiate(enemyPrefab, spawnPoint.position, startRotation);
    }


}
