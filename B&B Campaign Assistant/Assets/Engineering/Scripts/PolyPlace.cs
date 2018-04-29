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
	public float linewidth = .04f;
	public float lineheight = .02f;
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
		smartPolyLine();
		//spawnLine();
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

	private void smartPolyLine()     //goes through each vertex and figures out which lines need to be drawn
	{
		lineVertices = new Vector3[(polyscale - 2) * (polyscale - 2) * 8 * 6 + 2 * polyscale * 21];	//first is each set of eight potential lines from 
		int[] lineTriangles = new int[(polyscale - 1) * (polyscale - 1) * 36];
		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)	//these for loops go through all but the edge vertices. edge vertices are gone through later
			{
				bool[] heightDiff = vertexHeightDiff(x, z, false);
			}
		}
	}
	
	private bool[] vertexHeightDiff(int x, int z, bool isOffset)	//needs to be waterproofed for edges and near edges
	{
		bool[] diffs = new bool[8];
		for (int i = 0; i < 8; i++)
			diffs[i] = false;
		if(isOffset)
		{
			//working from offset agh
		}
		else
		{
			if (terrainVertices[z * polyscale + x].y != terrainVertices[z * polyscale + x + 1].y)
			{
				diffs[0] = true;
			}
			if (terrainVertices[z * polyscale + x].y != terrainVertices[z * polyscale + x - 1].y)
			{
				diffs[1] = true;
			}
			if (terrainVertices[z * polyscale + x].y != terrainVertices[(z + 1) * polyscale + x].y)
			{
				diffs[2] = true;
			}
			if (terrainVertices[z * polyscale + x].y != terrainVertices[(z - 1) * polyscale + x].y)
			{
				diffs[3] = true;
			}
			//go do the offset agh
		}
		return diffs;
	}

	private void polyLine()		//(theoretically) creates a complete 3d wireframe
	{
		lineVertices = new Vector3[(polyscale - 1) * (polyscale - 1) * 21 + 2 * polyscale * 21];    //areamap in the first polyscale square, the inbetweens in the second
		int[] lineTriangles = new int[(polyscale - 1) * (polyscale - 1) * 36];

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

				for(int i = 0;i < 6;i++)
				{
					Vector3[] rVertices = polyLineVertices(linePoints[i], linePoints[i + 1]);
					for (int ii = 0;ii < 3;ii++)
					{
						lineVertices[cur + i * 3 + ii] = rVertices[ii];
					}
				}
				Vector3[] endVertices = polyLineVertices(linePoints[5], linePoints[6]);
				for (int ii = 3; ii < 6; ii++)
				{
					lineVertices[cur + 15 + ii] = endVertices[ii];
				}

				for (int i = 0; i < 6; i++)
				{
					Vector3[] rVertices = new Vector3[6];
					rVertices[0] = lineVertices[cur + i * 3 + 0];
					rVertices[1] = lineVertices[cur + i * 3 + 1];
					rVertices[2] = lineVertices[cur + i * 3 + 2];
					rVertices[3] = lineVertices[cur + i * 3 + 3];
					rVertices[4] = lineVertices[cur + i * 3 + 4];
					rVertices[5] = lineVertices[cur + i * 3 + 5];
					int[] rTriangles = polyLineTriangles(rVertices, cur + i * 3);
					for (int ii = 0; ii < 18; ii++)
					{
						lineTriangles[(cur / 7) + i * 18 + ii] = rTriangles[ii];
					}
				}

				//increment
				cur += 21;
			}
		}
		polyLineMesh.GetComponent<MeshFilter>().mesh.vertices = lineVertices;
		polyLineMesh.GetComponent<MeshFilter>().mesh.triangles = lineTriangles;
		polyLineMesh.GetComponent<MeshFilter>().mesh.RecalculateNormals();
	}
	
	private Vector3[] polyLineVertices(Vector3 start, Vector3 end)		//returns a Vector3 holding the vertices of a polyLine
	{
		//both ends are vertical triangle
		print("start: " + start);
		print("end: " + end);
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
		triangles[0] = it + 0; triangles[1] = it + 1; triangles[2] = it + 2;
		triangles[3] = it + 0; triangles[4] = it + 2; triangles[5] = it + 3;
		triangles[6] = it + 3; triangles[7] = it + 2; triangles[8] = it + 5;
		triangles[9] = it + 5; triangles[10] = it + 4; triangles[11] = it + 3;
		triangles[12] = it + 2; triangles[13] = it + 1; triangles[14] = it + 4;
		triangles[15] = it + 5; triangles[16] = it + 2; triangles[17] = it + 4;
		return triangles;
	}

	private void spawnLine()
	{
		GameObject polyFine = new GameObject("Plane");
		polyFine.AddComponent<MeshFilter>();
		polyFine.AddComponent<MeshRenderer>();
		polyFine.GetComponent<MeshRenderer>().material = linemat;
		Vector3 start = new Vector3(0, 0, 0);
		Vector3 end = new Vector3(5, 0, 7);
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
		int[] tangles = new int[18];
		tangles[0] = 0; tangles[1] = 1; tangles[2] = 2;
		tangles[3] = 0; tangles[4] = 2; tangles[5] = 3;
		tangles[6] = 3; tangles[7] = 2; tangles[8] = 5;
		tangles[9] = 5; tangles[10] = 4; tangles[11] = 3;
		tangles[12] = 2; tangles[13] = 1; tangles[14] = 4;
		tangles[15] = 5; tangles[16] = 2; tangles[17] = 4;
		polyFine.GetComponent<MeshFilter>().mesh.vertices = vertices;
		polyFine.GetComponent<MeshFilter>().mesh.triangles = tangles;
		polyFine.GetComponent<MeshFilter>().mesh.RecalculateNormals();
	}
}
