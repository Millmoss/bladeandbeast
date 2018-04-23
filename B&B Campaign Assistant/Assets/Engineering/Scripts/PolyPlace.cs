using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PolyPlace : MonoBehaviour
{
	public Material terrainmat;
	public Material linemat;
	public int polyscale = 10;
	public float heightscale = 2;
	public float sizescale = 1;
	public float perlinscale = .75f;
	public float linewidth = .05f;
	public float lineheight = .035f;
	private Vector3[,] areaMap;
	private Vector3[] terrainVertices;
	private Vector3[] lineVertices;
	private GameObject polyTerrainMesh;
	private GameObject polyLineMesh;

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
		polyLineMesh = new GameObject("Plane");
		polyLineMesh.AddComponent<MeshFilter>();
		polyLineMesh.AddComponent<MeshRenderer>();
		polyLineMesh.GetComponent<MeshRenderer>().material = linemat;
		polyLine();
	}
	
	void Update ()
	{

	}

	public void polyTerrain()
	{
		terrainVertices = new Vector3[polyscale * polyscale + (polyscale - 1) * (polyscale - 1)];    //areamap in the first polyscale square, the inbetweens in the second
		int[] terrainTriangles = new int[(polyscale - 1) * (polyscale - 1) * 12];

		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				terrainVertices[z * polyscale + x] = areaMap[x, z];
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
				terrainVertices[polyscale * polyscale + ((polyscale - 1) * z) + x] = new Vector3(areaMap[x, z].x + .5f, (areaMap[mxa, mza].y + areaMap[mxb, mzb].y) / 2, areaMap[x, z].z + .5f);
			}
		}

		int cur = 0;
		for (int z = 0; z < polyscale - 1; z++)
		{
			for (int x = 0; x < polyscale - 1; x++)
			{
				//setting triangles
				terrainTriangles[cur + 2] = z * polyscale + x;
				terrainTriangles[cur + 1] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				terrainTriangles[cur + 0] = z * polyscale + x + 1;
				terrainTriangles[cur + 3] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				terrainTriangles[cur + 4] = z * polyscale + x + 1;
				terrainTriangles[cur + 5] = (z + 1) * polyscale + x + 1;
				terrainTriangles[cur + 8] = z * polyscale + x;
				terrainTriangles[cur + 7] = (z + 1) * polyscale + x;
				terrainTriangles[cur + 6] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				terrainTriangles[cur + 9] = (z + 1) * polyscale + x;
				terrainTriangles[cur + 10] = polyscale * polyscale + ((polyscale - 1) * z) + x;
				terrainTriangles[cur + 11] = (z + 1) * polyscale + x + 1;
				//increment
				cur += 12;
			}
		}
		polyTerrainMesh.GetComponent<MeshFilter>().mesh.vertices = terrainVertices;
		polyTerrainMesh.GetComponent<MeshFilter>().mesh.triangles = terrainTriangles;
		polyTerrainMesh.GetComponent<MeshFilter>().mesh.RecalculateNormals();
	}

	private void polyLine()		//will need to be edited to create not quite so many lines
	{
		lineVertices = new Vector3[(polyscale - 1) * (polyscale - 1) * 36 + 2 * polyscale * 36];    //areamap in the first polyscale square, the inbetweens in the second
		int[] lineTriangles = new int[(polyscale - 1) * (polyscale - 1) * 36 * 3];

		int cur = 0;
		for (int z = 0; z < polyscale - 1; z++)
		{
			for (int x = 0; x < polyscale - 1; x++)
			{
				Vector3[] linePoints = new Vector3[7];
				for (int i = 0; i < 7; i++)
					linePoints[i] = Vector3.zero;
				linePoints[0] += terrainVertices[z * polyscale + x];
				linePoints[1] += terrainVertices[polyscale * polyscale + ((polyscale - 1) * z) + x];
				linePoints[2] += terrainVertices[(z + 1) * polyscale + x + 1];
				linePoints[3] += terrainVertices[z * polyscale + x + 1];
				linePoints[4] += terrainVertices[polyscale * polyscale + ((polyscale - 1) * z) + x];
				linePoints[5] += terrainVertices[(z + 1) * polyscale + x];
				linePoints[6] += terrainVertices[(z + 1) * polyscale + x + 1];

				for(int i = 0;i < 6;i++)	//INEFFICIENT: switch to holding 7 sets of 3 vertices
				{
					Vector3[] rVertices = polyLineVertices(linePoints[i], linePoints[i + 1]);
					int[] rTriangles = polyLineTriangles(rVertices, cur + i * 36);
					for (int ii = 0;ii < 6;ii++)
					{
						lineVertices[cur + i * 6 + ii] = rVertices[ii];
					}
					for (int ii = 0; ii < 18; ii++)
					{
						lineTriangles[cur * 36 * 3 + i * 18 + ii] = rTriangles[ii];
					}
				}

				//increment
				cur += 36;
			}
		}
		polyLineMesh.GetComponent<MeshFilter>().mesh.vertices = lineVertices;
		polyLineMesh.GetComponent<MeshFilter>().mesh.triangles = lineTriangles;
		polyLineMesh.GetComponent<MeshFilter>().mesh.RecalculateNormals();
	}

	private Vector3[] polyLineVertices(Vector3 start, Vector3 end)		//returns a Vector3 holding the vertices of a polyLine
	{
		//both ends are vertical triangle
		Vector3 forward = end - start;
		Vector3 left = new Vector3(forward.z, forward.y, -forward.x).normalized / (1 / linewidth);
		Vector3 right = new Vector3(-forward.z, forward.y, forward.x).normalized / (1 / linewidth);
		Vector3 up = new Vector3(0, lineheight, 0);
		Vector3 startLeft = start + left;
		Vector3 startRight = start + right;
		Vector3 startUp = start + up;
		Vector3 endLeft = end + left;
		Vector3 endRight = end + right;
		Vector3 endUp = end + up;
		Vector3[] vertices = { startLeft, startRight, startUp, endLeft, endRight, endUp };
		return vertices;
	}

	private int[] polyLineTriangles(Vector3[] vertices, int it)      //returns a Vector3 holding the triangles of a polyLine
	{
		int[] triangles  = new int[18];
		triangles[0] = it + 0; triangles[1] = it + 1; triangles[2] = + 2;
		triangles[3] = it + 0; triangles[4] = it + 2; triangles[5] = + 3;
		triangles[6] = it + 2; triangles[7] = it + 3; triangles[8] = + 5;
		triangles[9] = it + 3; triangles[10] = it + 4; triangles[11] = + 5;
		triangles[12] = it + 1; triangles[13] = it + 2; triangles[14] = + 4;
		triangles[15] = it + 2; triangles[16] = it + 4; triangles[17] = + 5;
		return triangles;
	}
}
