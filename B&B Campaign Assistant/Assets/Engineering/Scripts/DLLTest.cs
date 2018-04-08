using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class DLLTest : MonoBehaviour
{
	//IMPORTS

	//imported character initialization method
	[DllImport("GameManager")] private static extern void createCharacter();

	//imported set methods
	[DllImport("GameManager")] private static extern int setName(int index, [MarshalAs(UnmanagedType.LPWStr)] string name);
	[DllImport("GameManager")] private static extern int setStrength(int index, int s);
	[DllImport("GameManager")] private static extern int setDexterity(int index, int d);
	[DllImport("GameManager")] private static extern int setAgility(int index, int a);
	[DllImport("GameManager")] private static extern int setConstitution(int index, int c);
	[DllImport("GameManager")] private static extern int setIntellect(int index, int i);
	[DllImport("GameManager")] private static extern int setWillpower(int index, int w);
	[DllImport("GameManager")] private static extern int setPerception(int index, int p);
	[DllImport("GameManager")] private static extern int setCharisma(int index, int c);
	[DllImport("GameManager")] private static extern int setBeauty(int index, int b);
	[DllImport("GameManager")] private static extern int setBirth(int index, int y, int d, int s);
	[DllImport("GameManager")] private static extern int setBaseHeight(int index, float h);
	[DllImport("GameManager")] private static extern int setBaseWeight(int index, float w);

	//imported get methods
	[DllImport("GameManager")] private static extern string getName(int index);
	[DllImport("GameManager")] private static extern int getStrength(int index);
	[DllImport("GameManager")] private static extern int getDexterity(int index);
	[DllImport("GameManager")] private static extern int getAgility(int index);
	[DllImport("GameManager")] private static extern int getConstitution(int index);
	[DllImport("GameManager")] private static extern int getIntellect(int index);
	[DllImport("GameManager")] private static extern int getWillpower(int index);
	[DllImport("GameManager")] private static extern int getPerception(int index);
	[DllImport("GameManager")] private static extern int getCharisma(int index);
	[DllImport("GameManager")] private static extern int getBeauty(int index);
	[DllImport("GameManager")] private static extern string getAge(int index);

	[DllImport("GameManager")] private static extern int getRestrictMax(int index);
	[DllImport("GameManager")] private static extern int getRestrict(int index);
	[DllImport("GameManager")] private static extern int getOverheatMax(int index);
	[DllImport("GameManager")] private static extern int getOverheat(int index);
	[DllImport("GameManager")] private static extern int getDamageBonus(int index);
	[DllImport("GameManager")] private static extern int getCarryMax(int index);
	[DllImport("GameManager")] private static extern float getCarry(int index);
	[DllImport("GameManager")] private static extern int getLiftMax(int index);
	[DllImport("GameManager")] private static extern int getWeaponProficiency(int index);
	[DllImport("GameManager")] private static extern int getInitiativeBase(int index);
	[DllImport("GameManager")] private static extern int getInitiative(int index);
	[DllImport("GameManager")] private static extern int getDefenseBase(int index);
	[DllImport("GameManager")] private static extern int getDefense(int index);
	[DllImport("GameManager")] private static extern int getHealthMax(int index);
	[DllImport("GameManager")] private static extern float getHealth(int index);
	[DllImport("GameManager")] private static extern float getHealSpeed(int index);
	[DllImport("GameManager")] private static extern float getBaseWeight(int index);
	[DllImport("GameManager")] private static extern float getBaseHeight(int index);
	[DllImport("GameManager")] private static extern float getWeight(int index);
	[DllImport("GameManager")] private static extern float getHeight(int index);
	[DllImport("GameManager")] private static extern int getResolve(int index);
	[DllImport("GameManager")] private static extern int getSorceryBonus(int index);
	[DllImport("GameManager")] private static extern int getEyeglassesBonus(int index);
	[DllImport("GameManager")] private static extern string getEyesight(int index);

	//LOCAL VARIABLES

	int characterCount;

	// Use this for initialization
	void Start () {
		createCharacter();
		characterCount++;
		setStrength(0, 10);
		setName(0, "BOBERT");
	}
	
	// Update is called once per frame
	void Update () {
		print(getStrength(0));
		print(getName(0));
	}
}
