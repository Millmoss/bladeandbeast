using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class GameManagerImporter : MonoBehaviour
{
	//IMPORTS

	//imported temporary dev methods
	//None

	//imported single-call initilizers
	[DllImport("GameManager")] public static extern bool initializeManager();

	//imported character initialization method
	[DllImport("GameManager")] public static extern int createCharacter();

	//exported save methods
	[DllImport("GameManager")] public static extern bool saveCharacter(int index);

	//imported set methods
	[DllImport("GameManager")] public static extern int setName(int index, string name);
	[DllImport("GameManager")] public static extern int setStrength(int index, int s);
	[DllImport("GameManager")] public static extern int setDexterity(int index, int d);
	[DllImport("GameManager")] public static extern int setAgility(int index, int a);
	[DllImport("GameManager")] public static extern int setConstitution(int index, int c);
	[DllImport("GameManager")] public static extern int setIntellect(int index, int i);
	[DllImport("GameManager")] public static extern int setWillpower(int index, int w);
	[DllImport("GameManager")] public static extern int setPerception(int index, int p);
	[DllImport("GameManager")] public static extern int setCharisma(int index, int c);
	[DllImport("GameManager")] public static extern int setBeauty(int index, int b);
	[DllImport("GameManager")] public static extern int setBirth(int index, int y, int d, int s);
	[DllImport("GameManager")] public static extern int setBaseHeight(int index, float h);
	[DllImport("GameManager")] public static extern int setBaseWeight(int index, float w);

	//imported get methods
	[DllImport("GameManager")] public static extern int getIndex(string name);
	[DllImport("GameManager")] public static extern System.IntPtr getName(int index);
	[DllImport("GameManager")] public static extern int getStrength(int index);
	[DllImport("GameManager")] public static extern int getDexterity(int index);
	[DllImport("GameManager")] public static extern int getAgility(int index);
	[DllImport("GameManager")] public static extern int getConstitution(int index);
	[DllImport("GameManager")] public static extern int getIntellect(int index);
	[DllImport("GameManager")] public static extern int getWillpower(int index);
	[DllImport("GameManager")] public static extern int getPerception(int index);
	[DllImport("GameManager")] public static extern int getCharisma(int index);
	[DllImport("GameManager")] public static extern int getBeauty(int index);
	[DllImport("GameManager")] public static extern System.IntPtr getAge(int index);

	[DllImport("GameManager")] public static extern int getRestrictMax(int index);
	[DllImport("GameManager")] public static extern int getRestrict(int index);
	[DllImport("GameManager")] public static extern int getOverheatMax(int index);
	[DllImport("GameManager")] public static extern int getOverheat(int index);
	[DllImport("GameManager")] public static extern int getDamageBonus(int index);
	[DllImport("GameManager")] public static extern int getCarryMax(int index);
	[DllImport("GameManager")] public static extern float getCarry(int index);
	[DllImport("GameManager")] public static extern int getLiftMax(int index);
	[DllImport("GameManager")] public static extern int getWeaponProficiency(int index);
	[DllImport("GameManager")] public static extern int getInitiativeBase(int index);
	[DllImport("GameManager")] public static extern int getInitiative(int index);
	[DllImport("GameManager")] public static extern int getDefenseBase(int index);
	[DllImport("GameManager")] public static extern int getDefense(int index);
	[DllImport("GameManager")] public static extern int getHealthMax(int index);
	[DllImport("GameManager")] public static extern float getHealth(int index);
	[DllImport("GameManager")] public static extern float getHealSpeed(int index);
	[DllImport("GameManager")] public static extern float getBaseWeight(int index);
	[DllImport("GameManager")] public static extern float getBaseHeight(int index);
	[DllImport("GameManager")] public static extern float getWeight(int index);
	[DllImport("GameManager")] public static extern float getHeight(int index);
	[DllImport("GameManager")] public static extern int getResolve(int index);
	[DllImport("GameManager")] public static extern int getSorceryBonus(int index);
	[DllImport("GameManager")] public static extern int getEyeglassesBonus(int index);
	[DllImport("GameManager")] public static extern System.IntPtr getEyesight(int index);

	//LOCAL VARIABLES

	int characterCount;
	
	void Start () {
		initializeManager();
		/*setStrength(0, 12);
		setDexterity(0, 11);
		setAgility(0, 17);
		setConstitution(0, 15);
		setIntellect(0, 1);
		setWillpower(0, 7);
		setPerception(0, 18);
		setCharisma(0, 8);
		setBeauty(0, 9);
		setBaseHeight(0, 49);
		setBaseWeight(0, 179);*/

		/*print(getStrength(0));
		print(getDexterity(0));
		print(getAgility(0));
		print(getConstitution(0));
		print(getIntellect(0));
		print(getWillpower(0));
		print(getPerception(0));
		print(getCharisma(0));
		print(getBeauty(0));
		print(getBaseHeight(0));
		print(getBaseWeight(0));
		saveCharacter(0);
		/*createCharacter();
		characterCount++;
		createCharacter();
		characterCount++;
		setStrength(0, 10);
		setName(0, "BOBERT");
		setName(1, "TOBERT");
		saveCharacter(0);
		saveCharacter(1);*/

		//print(setFileContents("what the fuck is happening"));
	}
	
	void Update () {
		//print(Marshal.PtrToStringAnsi(getName(0), 6));
		//print(Marshal.PtrToStringAnsi(getName(1), 6));
		//print(Marshal.PtrToStringAnsi(getFileContents()));
	}
}
