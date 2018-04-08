using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class DLLTest : MonoBehaviour
{
	[DllImport("GameManager")]
	private static extern void createCharacter(string name);

	[DllImport("GameManager")]
	private static extern void setStrength(int s);

	[DllImport("GameManager")]
	private static extern int getStrength();

	// Use this for initialization
	void Start () {
		createCharacter("GEOR");
		setStrength(5);
	}
	
	// Update is called once per frame
	void Update () {
		print(getStrength());
	}
}
