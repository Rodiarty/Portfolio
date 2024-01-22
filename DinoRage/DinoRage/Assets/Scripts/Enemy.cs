using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class Enemy : MonoBehaviour
{
    private float speed = 10f;

    public float startHealth = 100;
    private float health;

    public int value = 50;

    [Header("Unity Stuff")]
    public Image healthBar;
    public Canvas healthContainer;

    [HideInInspector]
    public static int enemyDead;


    private Camera camer;
    private Transform target;
    private int wavepointIndex = 0;
    private bool shouldMove = true;
    private bool isDead = false;

    private Animator myAnimator;

    private void Start()
    {
        target = WayPoints.points[0];
        health = startHealth;
        camer = Camera.main;
        myAnimator = GetComponent<Animator>();
    }

    private void Update()
    {
        if(health == startHealth)
        {
            healthContainer.enabled = false;
        }
        else healthContainer.enabled = true;
        if (shouldMove)
        {
            Vector3 direction = target.position - transform.position;
            transform.Translate(direction.normalized * speed * Time.deltaTime, Space.World);
            transform.LookAt(target.position);
            healthContainer.transform.LookAt(camer.transform.position);

            if (Vector3.Distance(transform.position, target.position) <= 0.4f)
            {
                GetNextWaypoint();
            }
            myAnimator.Play("TRex_Run");
        }
        else return;
    }

    public void TakeDamage(int amount)
    {
        health -= amount;
        healthBar.fillAmount = health / startHealth;

        if (health <= 0 && !isDead)
        {
            Die();
        }
    }

    private void GetNextWaypoint()
    {
        if (wavepointIndex >= WayPoints.points.Length - 1)
        {
            EndPath();
            return;
        }
        else
        {
            wavepointIndex++;
            target = WayPoints.points[wavepointIndex];
        }
    }

    void Die()
    {
        isDead = true;
        PlayerStats.Money += value;
        shouldMove = false; 
        myAnimator.Play("TRex_Death");
        StartCoroutine(DestroyAfterAnimation());
    }

    void EndPath()
    {
        PlayerStats.Lives--;
        Destroy(gameObject);
        enemyDead++;
    }

    private IEnumerator DestroyAfterAnimation()
    {
        yield return new WaitForSeconds(myAnimator.GetCurrentAnimatorStateInfo(0).length);
        Destroy(gameObject);
        enemyDead++;
    }
}
