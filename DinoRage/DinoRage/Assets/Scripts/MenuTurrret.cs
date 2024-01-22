using UnityEngine;

public class MenuTurrret : MonoBehaviour
{
    void Update()
    {
        Vector3 mousePosition = Input.mousePosition;
        mousePosition.z = Camera.main.transform.position.z;

        Vector3 targetPosition = Camera.main.ScreenToWorldPoint(mousePosition);

        transform.LookAt(targetPosition);
        transform.rotation = Quaternion.Euler(0f, transform.rotation.eulerAngles.y, 0f);
    }
}
