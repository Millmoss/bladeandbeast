extern "C"
{
	//all methods will return -1 or \0 if something goes wrong
	#define DllExport __declspec (dllexport)

	//player character data : data that the players and GM both have to have
	Character **characters;
	int characterCount;

	//item data : data that the players and GM both have to have
	Item **miscellaneousList;			//miscellaneous items
	int miscellaneousCount;
	Weapon **weaponList;				//weapons
	int weaponCount;
	Item **armorList;					//armor
	int armorCount;

	//creature data : data that only the GM must have, only data the GM wants the players to know is sent to the players
	Character **npcList;				//non-player character list
	int npcCount;
	//Creature **animalList;
	//int animalCount;
	//Monster **monsterList;
	//int monsterCount;

	//exported temporary dev methods
	//NONE AT THE MOMENT

	//exported single-call initializers
	DllExport bool initializeManager();

	//exported multi-call initializers
	DllExport int createCharacter();

	//exported save methods
	DllExport bool saveCharacter(int index);

	DllExport char *getCharacterList();

	//exported character set methods
	DllExport int setName(int index, char *name);
	DllExport int setStat(int index, int number, int stat);
	DllExport int setBirth(int index, int date, int ymd);
	DllExport int setBaseHeight(int index, float h);
	DllExport int setBaseWeight(int index, float w);

	//exported character get methods
	DllExport int getIndex(char *name);
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
	/*DllExport int getDefenseBase(int index);
	DllExport int getDefense(int index);*/
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
