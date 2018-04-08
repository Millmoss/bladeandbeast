#include <iostream>
#include <stdlib.h>
#include "Character.h"
#include "GameManager.h"

extern "C"
{
	Character characters;

	DllExport int createCharacter()
	{
		/*
		characters.emplace_back(new Character);
		return characters.size() - 1;*/
		return 0;
	}

	DllExport int setName(int index, char *name)
	{
		if (false)
			return -1;
		char *n = (char *)malloc(sizeof(char) * 32);
		strcpy_s(n, 32, name);
		characters.setName(n);
		return 0;
	}

	DllExport int setStrength(int index, int s)
	{
		if (false)
			return -1;
		characters.setStrength(s);
		return 0;
	}

	DllExport int setDexterity(int index, int d)
	{
		if (false)
			return -1;
		characters.setDexterity(d);
		return 0;
	}

	DllExport int setAgility(int index, int a)
	{
		if (false)
			return -1;
		characters.setAgility(a);
		return 0;
	}

	DllExport int setConstitution(int index, int c)
	{
		if (false)
			return -1;
		characters.setConstitution(c);
		return 0;
	}

	DllExport int setIntellect(int index, int i)
	{
		if (false)
			return -1;
		characters.setIntellect(i);
		return 0;
	}

	DllExport int setWillpower(int index, int w)
	{
		if (false)
			return -1;
		characters.setWillpower(w);
		return 0;
	}

	DllExport int setPerception(int index, int p)
	{
		if (false)
			return -1;
		characters.setPerception(p);
		return 0;
	}

	DllExport int setCharisma(int index, int c)
	{
		if (false)
			return -1;
		characters.setCharisma(c);
		return 0;
	}

	DllExport int setBeauty(int index, int b)
	{
		if (false)
			return -1;
		characters.setBeauty(b);
		return 0;
	}

	DllExport int setBirth(int index, int y, int d, int s)
	{
		if (false)
			return -1;
		characters.setBirth(y, d, s);
		return 0;
	}

	DllExport int setBaseHeight(int index, float h)
	{
		if (false)
			return -1;
		characters.setBaseHeight(h);
		return 0;
	}

	DllExport int setBaseWeight(int index, float w)
	{
		if (false)
			return -1;
		characters.setBaseWeight(w);
		return 0;
	}

	DllExport char *getName(int index)
	{
		if (false)
		{
			char r[] = "\0";
			return r;
		}
		return characters.getName();
	}

	DllExport int getStrength(int index)
	{
		if (false)
			return -1;
		return characters.getStrength();
	}

	DllExport int getDexterity(int index)
	{
		if (false)
			return -1;
		return characters.getDexterity();
	}

	DllExport int getAgility(int index)
	{
		if (false)
			return -1;
		return characters.getAgility();
	}

	DllExport int getConstitution(int index)
	{
		if (false)
			return -1;
		return characters.getConstitution();
	}

	DllExport int getIntellect(int index)
	{
		if (false)
			return -1;
		return characters.getIntellect();
	}

	DllExport int getWillpower(int index)
	{
		if (false)
			return -1;
		return characters.getWillpower();
	}

	DllExport int getPerception(int index)
	{
		if (false)
			return -1;
		return characters.getPerception();
	}

	DllExport int getCharisma(int index)
	{
		if (false)
			return -1;
		return characters.getCharisma();
	}

	DllExport int getBeauty(int index)
	{
		if (false)
			return -1;
		return characters.getBeauty();
	}

	DllExport char *getAge(int index)
	{
		if (false)
		{
			char r[] = "\0";
			return r;
		}
		return characters.getAge();
	}

	DllExport int getRestrictMax(int index)
	{
		if (false)
			return -1;
		return characters.getRestrictMax();
	}

	DllExport int getRestrict(int index)
	{
		if (false)
			return -1;
		return characters.getRestrict();
	}

	DllExport int getOverheatMax(int index)
	{
		if (false)
			return -1;
		return characters.getOverheatMax();
	}

	DllExport int getOverheat(int index)
	{
		if (false)
			return -1;
		return characters.getOverheat();
	}

	DllExport int getDamageBonus(int index)
	{
		if (false)
			return -1;
		return characters.getDamageBonus();
	}

	DllExport int getCarryMax(int index)
	{
		if (false)
			return -1;
		return characters.getCarryMax();
	}

	DllExport float getCarry(int index)
	{
		if (false)
			return -1;
		return characters.getCarry();
	}

	DllExport int getLiftMax(int index)
	{
		if (false)
			return -1;
		return characters.getLiftMax();
	}

	DllExport int getWeaponProficiency(int index)
	{
		if (false)
			return -1;
		return characters.getWeaponProficiency();
	}

	DllExport int getInitiativeBase(int index)
	{
		if (false)
			return -1;
		return characters.getInitiativeBase();
	}

	DllExport int getInitiative(int index)
	{
		if (false)
			return -1;
		return characters.getInitiative();
	}

	DllExport int getDefenseBase(int index)
	{
		if (false)
			return -1;
		return characters.getDefenseBase();
	}

	DllExport int getDefense(int index)
	{
		if (false)
			return -1;
		return characters.getDefense();
	}

	DllExport int getHealthMax(int index)
	{
		if (false)
			return -1;
		return characters.getHealthMax();
	}

	DllExport float getHealth(int index)
	{
		if (false)
			return -1;
		return characters.getHealth();
	}

	DllExport float getHealSpeed(int index)
	{
		if (false)
			return -1;
		return characters.getHealSpeed();
	}

	DllExport float getBaseWeight(int index)
	{
		if (false)
			return -1;
		return characters.getBaseWeight();
	}

	DllExport float getBaseHeight(int index)
	{
		if (false)
			return -1;
		return characters.getBaseHeight();
	}

	DllExport float getWeight(int index)
	{
		if (false)
			return -1;
		return characters.getWeight();
	}

	DllExport float getHeight(int index)
	{
		if (false)
			return -1;
		return characters.getHeight();
	}

	DllExport int getResolve(int index)
	{
		if (false)
			return -1;
		return characters.getResolve();
	}

	DllExport int getSorceryBonus(int index)
	{
		if (false)
			return -1;
		return characters.getSorceryBonus();
	}

	DllExport int getEyeglassesBonus(int index)
	{
		if (false)
			return -1;
		return characters.getEyeglassesBonus();
	}

	DllExport char *getEyesight(int index)
	{
		if (false)
		{
			char r[] = "\0";
			return r;
		}
		return characters.getEyesight();
	}
}