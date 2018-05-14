using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PolyTerrain : MonoBehaviour
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

	void Start ()
	{
		areaMap = new Vector3[polyscale, polyscale];
		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				areaMap[z, x] = new Vector3(x * sizescale, Mathf.Ceil(Mathf.PerlinNoise(x * perlinscale, z * perlinscale) * heightscale * 10) / 10, z * sizescale);
			}
		}
		polyTerrainMesh = new GameObject("Plane");
		polyTerrainMesh.layer = 9;
		polyTerrainMesh.AddComponent<MeshFilter>();
		polyTerrainMesh.AddComponent<MeshRenderer>();
		polyTerrainMesh.GetComponent<MeshRenderer>().material = terrainmat;
		polyTerrain();
		polyLineMesh = new GameObject("Plane");
		polyLineMesh.AddComponent<MeshFilter>();
		polyLineMesh.AddComponent<MeshRenderer>();
		polyLineMesh.GetComponent<MeshRenderer>().material = linemat;
		//smartPolyLine();
		//spawnLine();
	}
	
	void Update ()
	{
		//for a cave do I just place extra height in a cave shape on some terrain?
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
				float y = (areaMap[x, z].y + areaMap[x + 1, z].y + areaMap[x, z + 1].y + areaMap[x + 1, z + 1].y) / 4;
				terrainVertices[polyscale * polyscale + ((polyscale - 1) * z) + x] = new Vector3(areaMap[x, z].x + .5f * sizescale, y, areaMap[x, z].z + .5f * sizescale);
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

		Vector2[] terrainUV = new Vector2[terrainVertices.Length];

		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				terrainUV[z * polyscale + x] = new Vector2(areaMap[x, z].z / polyscale / 5, areaMap[x, z].x / polyscale / 5);
			}
		}

		for (int z = 0; z < polyscale - 1; z++)
		{
			for (int x = 0; x < polyscale - 1; x++)
			{
				terrainUV[polyscale * polyscale + ((polyscale - 1) * z) + x] = new Vector2((areaMap[x, z].z + .5f * sizescale) / polyscale / 5, (areaMap[x, z].x + .5f * sizescale) / polyscale / 5);
			}
		}

		polyTerrainMesh.GetComponent<MeshFilter>().mesh.uv = terrainUV;
		
		Texture2D terrainTexture = new Texture2D(polyscale, polyscale, TextureFormat.ARGB32, false);

		Color gr = Color.green;
		gr = new Color(gr.r, gr.g, gr.b);

		for (int z = 0; z < polyscale; z++)
		{
			for (int x = 0; x < polyscale; x++)
			{
				terrainTexture.SetPixel(x, z, new Color(gr.r * (.4f * areaMap[x, z].y / heightscale) + gr.r / 4, gr.g * (.4f * areaMap[x, z].y / heightscale) + gr.g / 4, gr.b * (.4f * areaMap[x, z].y / heightscale) + gr.b / 4, 0));
			}
		}
		terrainTexture.Apply();
		
		terrainmat.mainTexture = terrainTexture;

		polyTerrainMesh.AddComponent<MeshCollider>();
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
