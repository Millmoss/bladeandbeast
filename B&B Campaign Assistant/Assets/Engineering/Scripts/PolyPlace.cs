using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PolyPlace : MonoBehaviour
{
	public Material terrainmat;
	public Material blackUnlit;
	public int polyscale = 10;
	public float heightscale = 2;
	public float sizescale = 1;
	public float perlinscale = .75f;
	private Vector3[,] areaMap;
	private Vector3[] vertexList;
	private GameObject polyTerrainMesh;

	void Start ()	//redo code to deal with heights better maybe? consider Unity line renderer or custom line renderer
	{
		areaMap = new Vector3[polyscale, polyscale];
		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				areaMap[z, x] = new Vector3(x * sizescale, Mathf.Ceil(Mathf.PerlinNoise(x * perlinscale / polyscale, z * perlinscale / polyscale) * heightscale * 10) / 10, z * sizescale);
			}
		}
		polyTerrainMesh = new GameObject("Plane");
		polyTerrainMesh.AddComponent<MeshFilter>();
		polyTerrainMesh.AddComponent<MeshRenderer>();
		polyTerrainMesh.GetComponent<MeshRenderer>().material = terrainmat;
		polyTerrain();
	}
	
	void Update ()
	{

	}

	public void polyTerrain()
	{
		vertexList = new Vector3[polyscale * polyscale + (polyscale - 1) * (polyscale - 1)];    //areamap in the first polyscale square, the inbetweens in the second
		int[] triangleList = new int[(polyscale - 1) * (polyscale - 1) * 12];

		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				vertexList[z * polyscale + x] = areaMap[x, z];
			}
		}

		for (int z = 0; z < polyscale - 1; z++)
		{
			for (int x = 0; x < polyscale - 1; x++)
			{
				int mxa = x + Mathf.RoundToInt(Random.value);
				int mza = z + Mathf.RoundToInt(Random.value);
				int mxb = x + Mathf.RoundToInt(Random.value);
				int mzb = z + Mathf.RoundToInt(Random.value);
				vertexList[polyscale * polyscale + ((polyscale - 1) * z) + x] = new Vector3(areaMap[x, z].x + .5f, (areaMap[mxa, mza].y + areaMap[mxb, mzb].y) / 2, areaMap[x, z].z + .5f);
			}
		}

		int cur = 0;
		for (int z = 0; z < polyscale - 1; z++)
		{
			for (int x = 0; x < polyscale - 1; x++)
			{
				//setting triangles
				triangleList[cur + 2] = z * polyscale + x;
				triangleList[cur + 1] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				triangleList[cur + 0] = z * polyscale + x + 1;
				triangleList[cur + 3] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				triangleList[cur + 4] = z * polyscale + x + 1;
				triangleList[cur + 5] = (z + 1) * polyscale + x + 1;
				triangleList[cur + 8] = z * polyscale + x;
				triangleList[cur + 7] = (z + 1) * polyscale + x;
				triangleList[cur + 6] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				triangleList[cur + 9] = (z + 1) * polyscale + x;
				triangleList[cur + 10] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				triangleList[cur + 11] = (z + 1) * polyscale + x + 1;

				//creating necessary render lines, reuse the code once polyLine is made
				/*GameObject temp = new GameObject();
				LineRenderer lr = temp.AddComponent<LineRenderer>();
				lr.startWidth = .05f;
				lr.endWidth = .05f;
				//lr.widthCurve = AnimationCurve.Constant(0, 1, 1);
				lr.material = blackUnlit;
				lr.receiveShadows = false;
				lr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
				lr.positionCount = 7;
				Vector3[] linePoints = new Vector3[7];
				for (int i = 0; i < 7; i++)
					linePoints[i] = new Vector3(0, .1f);
				linePoints[0] += vertexList[z * polyscale + x];
				linePoints[1] += vertexList[polyscale * polyscale + ((polyscale - 1) * z) + x];
				linePoints[2] += vertexList[(z + 1) * polyscale + x + 1];
				linePoints[3] += vertexList[z * polyscale + x + 1];
				linePoints[4] += vertexList[polyscale * polyscale + ((polyscale - 1) * z) + x];
				linePoints[5] += vertexList[(z + 1) * polyscale + x];
				linePoints[6] += vertexList[(z + 1) * polyscale + x + 1];
				lr.SetPositions(linePoints);*/

				//increment
				cur += 12;
			}
		}
		polyTerrainMesh.GetComponent<MeshFilter>().mesh.vertices = vertexList;
		polyTerrainMesh.GetComponent<MeshFilter>().mesh.triangles = triangleList;
		polyTerrainMesh.GetComponent<MeshFilter>().mesh.RecalculateNormals();
	}

	private Vector3[,] polyLine(Vector3 start, Vector3 end)		//returns a Vector3 holding vertices and a Vector3 holding triangles to be added to the polyLineMesh
	{
		//both ends are vertical triangle
		Vector3 startLeft = 
		return ;	//temp
	}
}
