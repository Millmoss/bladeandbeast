using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PolyBrick	: MonoBehaviour
{


	void Start ()
	{
		
	}
	
	void Update ()
	{
		//INDIVIDUAL BRICKS OR ONE BRICK MESH? IN THIS CASE INDIVIDUAL BRICKS MAY WORK OUT BETTER???
	}

	/*private GameObject buildBricks(float[,] heightsAndOffsets, float width, float length, float height, float edge, float weathering, float chipping)
	{
		GameObject brick = new GameObject();
		brick.AddComponent<MeshFilter>();
		brick.AddComponent<MeshRenderer>();
		float chipValue = Mathf.CeilToInt(chipping) * 5;
		if (chipValue < .5f)
			chipValue = 1;
		else if (chipValue < 1)
			chipValue = 2;
		Vector3[] brickVertices = new Vector3[(int)chipValue * heightsAndOffsets.Length * 24 + heightsAndOffsets.Length];   //inefficient array storage converted to efficient array storage once all bricks are generated
		int[] brickTriangles = new int[3 * heightsAndOffsets.Length * (8 + 16 + ];

		for(int i = 0;i < heightsAndOffsets.Length;i++)
		{
			Mesh brickMesh = makeBrick(width, length, height, edge, weathering, chipping);

		}

		return brick;
	}

	private Mesh makeBrick(float width, float length, float height, float edge, float weathering, float chipping)
	{
		Mesh brickMesh = new Mesh();
		return brickMesh;
	}*/
}
