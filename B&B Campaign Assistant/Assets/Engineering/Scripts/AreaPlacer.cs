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
		int polyscale = 10;
		int sizescale = 10;
		float perlinscale = .75f;
		areaMap = new Vector3[polyscale, polyscale];
		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				areaMap[z, x] = new Vector3(.1f * x * sizescale, Mathf.PerlinNoise(x * perlinscale, z * perlinscale), .1f * z * sizescale);
			}
		}
		GameObject r = new GameObject("Plane");
		r.AddComponent<MeshFilter>();
		r.AddComponent<MeshRenderer>();
		r.GetComponent<MeshRenderer>().material = blue;
		Vector3[] vertexList = new Vector3[polyscale * polyscale];
		int[] triangleList = new int[(polyscale - 1) * (polyscale - 1) * 6];

		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				vertexList[z * polyscale + x] = areaMap[x, z];
			}
		}
		int cur = 0;
		for (int z = 0; z < polyscale - 1; z++)
		{
			for (int x = 0; x < polyscale - 1; x++)
			{
				triangleList[cur + 2] = z * polyscale + x;
				triangleList[cur + 1] = (z + 1) * polyscale + x;
				triangleList[cur + 0] = z * polyscale + x + 1;
				triangleList[cur + 3] = (z + 1) * polyscale + x;
				triangleList[cur + 4] = z * polyscale + x + 1;
				triangleList[cur + 5] = (z + 1) * polyscale + x + 1;
				cur += 6;
			}
		}
		r.GetComponent<MeshFilter>().mesh.vertices = vertexList;
		r.GetComponent<MeshFilter>().mesh.triangles = triangleList;
		r.GetComponent<MeshFilter>().mesh.RecalculateNormals();
	}
	
	void Update ()
	{

	}
}

//Renderer change = areaMap[z, x].GetComponent<Renderer>();
//change.material = blue;