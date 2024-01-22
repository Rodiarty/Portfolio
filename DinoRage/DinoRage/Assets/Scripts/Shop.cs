using UnityEngine;

public class Shop : MonoBehaviour
{
    public TurretBlueprint Turret;
    public TurretBlueprint TurretLVL2;

    BuildManager buildManager;

    void Start()
    {
        buildManager = BuildManager.instance;
    }

    public void SelectTurretLVL1()
    {
        Debug.Log("Standard Turret Selected");
        buildManager.SelectTurretToBuild(Turret);
    }

    public void SelectTurretLVL2()
    {
        Debug.Log("Another Turret Selected");
        buildManager.SelectTurretToBuild(TurretLVL2);
    }

}