extern "C"
{
	//all methods will return -1 or \0 if something goes wrong
	#define DllExport __declspec (dllexport)

	//initilize a new character
	DllExport int createCharacter();

	//exported set methods
	DllExport int setName(int index, char *name);
	DllExport int setStrength(int index, int s);
	DllExport int setDexterity(int index, int d);
	DllExport int setAgility(int index, int a);
	DllExport int setConstitution(int index, int c);
	DllExport int setIntellect(int index, int i);
	DllExport int setWillpower(int index, int w);
	DllExport int setPerception(int index, int p);
	DllExport int setCharisma(int index, int c);
	DllExport int setBeauty(int index, int b);
	DllExport int setBirth(int index, int y, int d, int s);
	DllExport int setBaseHeight(int index, float h);
	DllExport int setBaseWeight(int index, float w);

	//exported get methods
	DllExport char *getName(int index);
	DllExport int getStrength(int index);
	DllExport int getDexterity(int index);
	DllExport int getAgility(int index);
	DllExport int getConstitution(int index);
	DllExport int getIntellect(int index);
	DllExport int getWillpower(int index);
	DllExport int getPerception(int index);
	DllExport int getCharisma(int index);
	DllExport int getBeauty(int index);
	DllExport char *getAge(int index);

	DllExport int getRestrictMax(int index);
	DllExport int getRestrict(int index);
	DllExport int getOverheatMax(int index);
	DllExport int getOverheat(int index);
	DllExport int getDamageBonus(int index);
	DllExport int getCarryMax(int index);
	DllExport float getCarry(int index);
	DllExport int getLiftMax(int index);
	DllExport int getWeaponProficiency(int index);
	DllExport int getInitiativeBase(int index);
	DllExport int getInitiative(int index);
	DllExport int getDefenseBase(int index);
	DllExport int getDefense(int index);
	DllExport int getHealthMax(int index);
	DllExport float getHealth(int index);
	DllExport float getHealSpeed(int index);
	DllExport float getBaseWeight(int index);
	DllExport float getBaseHeight(int index);
	DllExport float getWeight(int index);
	DllExport float getHeight(int index);
	DllExport int getResolve(int index);
	DllExport int getSorceryBonus(int index);
	DllExport int getEyeglassesBonus(int index);
	DllExport char *getEyesight(int index);
}