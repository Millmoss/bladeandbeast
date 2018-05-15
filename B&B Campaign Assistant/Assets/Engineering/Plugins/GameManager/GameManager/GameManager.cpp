#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Character.h"
#include "GameManager.h"

extern "C"
{
	DllExport bool setFileContents(char *contents)
	{
		FILE *file;
		fopen_s(&file, "contents.txt", "w");
		fprintf_s(file, contents);
		fclose(file);
		return true;
	}

	DllExport char *getFileContents()
	{
		char *contents = (char *)malloc(1000 * sizeof(char));
		char c;
		int n = 0;
		FILE *file;
		fopen_s(&file, "wow.txt", "r");
		if (file) {
			while ((c = getc(file)) != EOF)
			{
				contents[n] = c;
				n++;
			}
			fclose(file);
		}
		contents[n] = '\0';
		return contents;
	}

	DllExport bool createItems()
	{
		//DO FILE READING AND DATA PREPARATION HERE
		return true;
	}

	DllExport int createCharacter()
	{
		if (characterCount == 0)
			characters = (Character **)malloc(sizeof(Character *));
		else
		{
			characters = (Character **)realloc((Character **)characters, sizeof(Character *) * (characterCount + 1));
		}
		Character *c = new Character;
		characters[characterCount] = c;
		characterCount++;
		return 0;
	}

#pragma region Character set and get methods

	DllExport int setName(int index, char *name)
	{
		if (index >= characterCount)
			return -1;
		char *n = (char *)malloc(sizeof(char) * 32);
		strcpy_s(n, 32, name);
		(*characters[index]).setName(n);
		return 0;
	}

	DllExport int setStrength(int index, int s)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setStrength(s);
		return 0;
	}

	DllExport int setDexterity(int index, int d)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setDexterity(d);
		return 0;
	}

	DllExport int setAgility(int index, int a)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setAgility(a);
		return 0;
	}

	DllExport int setConstitution(int index, int c)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setConstitution(c);
		return 0;
	}

	DllExport int setIntellect(int index, int i)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setIntellect(i);
		return 0;
	}

	DllExport int setWillpower(int index, int w)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setWillpower(w);
		return 0;
	}

	DllExport int setPerception(int index, int p)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setPerception(p);
		return 0;
	}

	DllExport int setCharisma(int index, int c)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setCharisma(c);
		return 0;
	}

	DllExport int setBeauty(int index, int b)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setBeauty(b);
		return 0;
	}

	DllExport int setBirth(int index, int y, int d, int s)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setBirth(y, d, s);
		return 0;
	}

	DllExport int setBaseHeight(int index, float h)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setBaseHeight(h);
		return 0;
	}

	DllExport int setBaseWeight(int index, float w)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setBaseWeight(w);
		return 0;
	}

	DllExport char *getName(int index)
	{
		if (index >= characterCount)
		{
			char r[] = "\0";
			return r;
		}
		return (*characters[index]).getName();
	}

	DllExport int getStrength(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getStrength();
	}

	DllExport int getDexterity(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getDexterity();
	}

	DllExport int getAgility(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getAgility();
	}

	DllExport int getConstitution(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getConstitution();
	}

	DllExport int getIntellect(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getIntellect();
	}

	DllExport int getWillpower(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getWillpower();
	}

	DllExport int getPerception(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getPerception();
	}

	DllExport int getCharisma(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getCharisma();
	}

	DllExport int getBeauty(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getBeauty();
	}

	DllExport char *getAge(int index)
	{
		if (index >= characterCount)
		{
			char r[] = "\0";
			return r;
		}
		return (*characters[index]).getAge();
	}

	DllExport int getRestrictMax(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getRestrictMax();
	}

	DllExport int getRestrict(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getRestrict();
	}

	DllExport int getOverheatMax(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getOverheatMax();
	}

	DllExport int getOverheat(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getOverheat();
	}

	DllExport int getDamageBonus(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getDamageBonus();
	}

	DllExport int getCarryMax(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getCarryMax();
	}

	DllExport float getCarry(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getCarry();
	}

	DllExport int getLiftMax(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getLiftMax();
	}

	DllExport int getWeaponProficiency(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getWeaponProficiency();
	}

	DllExport int getInitiativeBase(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getInitiativeBase();
	}

	DllExport int getInitiative(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getInitiative();
	}

	DllExport int getDefenseBase(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getDefenseBase();
	}

	DllExport int getDefense(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getDefense();
	}

	DllExport int getHealthMax(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getHealthMax();
	}

	DllExport float getHealth(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getHealth();
	}

	DllExport float getHealSpeed(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getHealSpeed();
	}

	DllExport float getBaseWeight(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getBaseWeight();
	}

	DllExport float getBaseHeight(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getBaseHeight();
	}

	DllExport float getWeight(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getWeight();
	}

	DllExport float getHeight(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getHeight();
	}

	DllExport int getResolve(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getResolve();
	}

	DllExport int getSorceryBonus(int index)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getSorceryBonus();
	}

	DllExport int getEyeglassesBonus(int index)
	{
		if (false)
			return -1;
		return (*characters[index]).getEyeglassesBonus();
	}

	DllExport char *getEyesight(int index)
	{
		if (false)
		{
			char r[] = "\0";
			return r;
		}
		return (*characters[index]).getEyesight();
	}
}

#pragma endregion
