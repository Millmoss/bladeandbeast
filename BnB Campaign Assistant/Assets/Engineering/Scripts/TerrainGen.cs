using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class TerrainGen : MonoBehaviour
{
    [DllImport("TerrainGenerator")]
    private static extern void generateTerrain(int x, int y);

    [DllImport("TerrainGenerator")]
    private static extern int getTerrain(int x, int y);
	
	void Start ()
	{
		generateTerrain(5, 5);
	}
	
	void Update ()
	{
        //print(getTerrain(2, 3));
	}
}
