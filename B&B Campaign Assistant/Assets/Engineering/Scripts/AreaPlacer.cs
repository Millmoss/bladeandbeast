using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AreaPlacer : MonoBehaviour
{
	private Vector3[,] areaMap;
	public Material red;
	public Material blue;
	public Material green;

	void Start ()
	{
		areaMap = new Vector3[100, 100];
		for (int z = 0; z < 100; z++)
		{
			for (int x = 0; x < 100; x++)
			{
				//areaMap[z, x] = GameObject.CreatePrimitive(PrimitiveType.Cube);
				//areaMap[z, x].transform.localScale = new Vector3(.1f, .5f, .1f);
				//Destroy(areaMap[z, x].GetComponent<BoxCollider>());
				areaMap[z, x] = new Vector3(.1f * x, Mathf.PerlinNoise(x * .1f, z * .1f), .1f * z);
				//float r = Random.value;
				//Renderer change = areaMap[z, x].GetComponent<Renderer>();
				//change.material = blue;
			}
		}
		GameObject r = new GameObject("Plane");
		r.AddComponent<MeshFilter>();
		r.AddComponent<MeshRenderer>();
		r.GetComponent<MeshRenderer>().material = blue;
		Vector3[] vertexList = new Vector3[10000];
		int[] triangleList = new int[58806];

		for (int z = 0; z < 100; z++)
		{
			for (int x = 0; x < 100; x++)
			{
				vertexList[z * 100 + x] = areaMap[x, z];
			}
		}
		int cur = 0;
		for (int z = 0; z < 99; z++)
		{
			for (int x = 0; x < 99; x++)
			{
				triangleList[cur + 2] = z * 100 + x;
				triangleList[cur + 1] = (z + 1) * 100 + x;
				triangleList[cur + 0] = z * 100 + x + 1;
				triangleList[cur + 3] = (z + 1) * 100 + x;
				triangleList[cur + 4] = z * 100 + x + 1;
				triangleList[cur + 5] = (z + 1) * 100 + x + 1;
				cur += 6;
			}
		}
		r.GetComponent<MeshFilter>().mesh.vertices = vertexList;
		r.GetComponent<MeshFilter>().mesh.triangles = triangleList;
	}
	
	void Update ()
	{

	}
}
