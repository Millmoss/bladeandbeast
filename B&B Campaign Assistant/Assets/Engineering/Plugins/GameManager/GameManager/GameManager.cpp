#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Character.h"
#include "GameManager.h"

std::vector<Character> characters;

DllExport int createCharacter()
{
	Character character;
	characters.push_back(character);
	return characters.size() - 1;
}

DllExport int setName(int index, char *name)
{
	if (index >= characters.size())
		return -1;
	characters[index].setName(name);
}

DllExport int setStrength(int index, int s)
{
	if (index >= characters.size())
		return -1;
	characters[index].setStrength(s);
}

DllExport int setDexterity(int index, int d)
{
	if (index >= characters.size())
		return -1;
	characters[index].setDexterity(d);
}

DllExport int setAgility(int index, int a)
{
	if (index >= characters.size())
		return -1;
	characters[index].setAgility(a);
}

DllExport int setConstitution(int index, int c)
{
	if (index >= characters.size())
		return -1;
	characters[index].setConstitution(c);
}

DllExport int setIntellect(int index, int i)
{
	if (index >= characters.size())
		return -1;
	characters[index].setIntellect(i);
}

DllExport int setWillpower(int index, int w)
{
	if (index >= characters.size())
		return -1;
	characters[index].setWillpower(w);
}

DllExport int setPerception(int index, int p)
{
	if (index >= characters.size())
		return -1;
	characters[index].setPerception(p);
}

DllExport int setCharisma(int index, int c)
{
	if (index >= characters.size())
		return -1;
	characters[index].setCharisma(c);
}

DllExport int setBeauty(int index, int b)
{
	if (index >= characters.size())
		return -1;
	characters[index].setBeauty(b);
}

DllExport int setBirth(int index, int y, int d, int s)
{
	if (index >= characters.size())
		return -1;
	characters[index].setBirth(y, d, s);
}

DllExport int setBaseHeight(int index, float h)
{
	if (index >= characters.size())
		return -1;
	characters[index].setBaseHeight(h);
}

DllExport int setBaseWeight(int index, float w)
{
	if (index >= characters.size())
		return -1;
	characters[index].setBaseWeight(w);
}

DllExport char *getName(int index)
{
	if (index >= characters.size())
	{
		char r[] = "\0";
		return r;
	}
	return characters[index].getName();
}

DllExport int getStrength(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getStrength();
}

DllExport int getDexterity(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getDexterity();
}

DllExport int getAgility(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getAgility();
}

DllExport int getConstitution(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getConstitution();
}

DllExport int getIntellect(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getIntellect();
}

DllExport int getWillpower(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getWillpower();
}

DllExport int getPerception(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getPerception();
}

DllExport int getCharisma(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getCharisma();
}

DllExport int getBeauty(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getBeauty();
}

DllExport char *getAge(int index)
{
	if (index >= characters.size())
	{
		char r[] = "\0";
		return r;
	}
	return characters[index].getAge();
}

DllExport int getRestrictMax(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getRestrictMax();
}

DllExport int getRestrict(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getRestrict();
}

DllExport int getOverheatMax(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getOverheatMax();
}

DllExport int getOverheat(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getOverheat();
}

DllExport int getDamageBonus(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getDamageBonus();
}

DllExport int getCarryMax(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getCarryMax();
}

DllExport float getCarry(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getCarry();
}

DllExport int getLiftMax(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getLiftMax();
}

DllExport int getWeaponProficiency(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getWeaponProficiency();
}

DllExport int getInitiativeBase(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getInitiativeBase();
}

DllExport int getInitiative(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getInitiative();
}

DllExport int getDefenseBase(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getDefenseBase();
}

DllExport int getDefense(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getDefense();
}

DllExport int getHealthMax(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getHealthMax();
}

DllExport float getHealth(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getHealth();
}

DllExport float getHealSpeed(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getHealSpeed();
}

DllExport float getBaseWeight(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getBaseWeight();
}

DllExport float getBaseHeight(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getBaseHeight();
}

DllExport float getWeight(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getWeight();
}

DllExport float getHeight(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getHeight();
}

DllExport int getResolve(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getResolve();
}

DllExport int getSorceryBonus(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getSorceryBonus();
}

DllExport int getEyeglassesBonus(int index)
{
	if (index >= characters.size())
		return -1;
	return characters[index].getEyeglassesBonus();
}

DllExport char *getEyesight(int index)
{
	if (index >= characters.size())
	{
		char r[] = "\0";
		return r;
	}
	return characters[index].getEyesight();
}
