#include <iostream>
#include <filesystem>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "Character.h"
#include "DataManager.h"
#include "GameManager.h"

namespace fs = std::experimental::filesystem;

extern "C"
{
	//file reading/writing example code
	/*
	DllExport bool setFileContents(char *contents)
	{
		try
		{
			fs::create_directories("Blade&BeastSaves/Contents");
			FILE *file;
			fopen_s(&file, "Blade&BeastSaves\\Contents\\contents.txt", "w");
			fprintf_s(file, contents);
			fclose(file);
			return true;
		}
		catch (const fs::filesystem_error& e)
		{
			FILE *file;
			fopen_s(&file, "error.txt", "w");
			fprintf_s(file, e.what());
			fprintf_s(file, "\nThis is a c++ filesystem error.");
			fclose(file);
			return false;
		}
	}

	DllExport char *getFileContents()
	{
		char *contents = (char *)malloc(1000 * sizeof(char));
		char c;
		int n = 0;
		FILE *file;
		fopen_s(&file, "Blade&BeastSaves\\Contents\\contents.txt", "r");
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
	*/

	DllExport bool initializeManager()	//this method will need to be refactored and potentially multi-threaded
	{
		/*bool t = fs::create_directories("Blade&BeastSaves/Characters");	//should check what directories exist

		std::string path = "Blade&BeastSaves/Characters";
		int i = 0;
		for (auto & p : fs::directory_iterator(path))
		{
			createCharacter();
			std::ostringstream out;
			out << p;
			FILE *file;
			fopen_s(&file, out.str().c_str(), "r");
			char descriptionBuffer[256];
			char valueBuffer[64];
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setName(valueBuffer);
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setStrength(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setDexterity(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setAgility(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setConstitution(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setIntellect(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setWillpower(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setPerception(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setCharisma(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setBeauty(atoi(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			//characters[i]->setAge(valueBuffer);	//fuck you john cena
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setBaseWeight(atof(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			characters[i]->setBaseHeight(atof(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			//characters[i]->setWeight(atof(valueBuffer));
			fgets(descriptionBuffer, sizeof(descriptionBuffer), file);
			fgets(valueBuffer, 64, file);
			valueBuffer[strlen(valueBuffer) - 1] = '\0';
			//characters[i]->setHeight(atof(valueBuffer));		//fucking john cena again goddamnit
			fclose(file);
			i++;
		}
		characterCount = i;*/
		
		DataManager bigData = DataManager();

		//DO FILE READING AND DATA PREPARATION HERE
		//Upon being called, should also reload all data from Blade & Beast Saves
		return true;
	}

	/*DllExport int createCharacter()
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

	DllExport bool saveCharacter(int index)	//this should be called automatically after any character sheet change
	{
		if (characterCount <= index)
			return false;
		FILE *file;
		char *path = (char *)malloc(sizeof(char) * 128);
		char *name = characters[index]->getName();
		sprintf_s(path, 128, "Blade&BeastSaves\\Characters\\%s.txt", name);
		fopen_s(&file, path, "w");
		if (file != NULL)
		{
			fprintf_s(file, "Basic Character Info\n");
			fprintf_s(file, "Name\n%s\n", characters[index]->getName());
			fprintf_s(file, "?\n%d\n", characters[index]->getStrength());
			fprintf_s(file, "?\n%d\n", characters[index]->getDexterity());
			fprintf_s(file, "?\n%d\n", characters[index]->getAgility());
			fprintf_s(file, "?\n%d\n", characters[index]->getConstitution());
			fprintf_s(file, "?\n%d\n", characters[index]->getIntellect());
			fprintf_s(file, "?\n%d\n", characters[index]->getWillpower());
			fprintf_s(file, "?\n%d\n", characters[index]->getPerception());
			fprintf_s(file, "?\n%d\n", characters[index]->getCharisma());
			fprintf_s(file, "?\n%d\n", characters[index]->getBeauty());
			fprintf_s(file, "?\n%s\n", characters[index]->getAge());
			fprintf_s(file, "?\n%f\n", characters[index]->getBaseWeight());
			fprintf_s(file, "?\n%f\n", characters[index]->getBaseHeight());
			fprintf_s(file, "?\n%f\n", characters[index]->getWeight());
			fprintf_s(file, "?\n%f\n", characters[index]->getHeight());
			fclose(file);
		}
		else
		{
			FILE *file;
			fopen_s(&file, "error.txt", "w");
			fprintf_s(file, "This is a file saving error with |%s|", characters[index]->getName());
			fclose(file);
			return false;
		}
		free(path);
		return true;
	}

	DllExport char *getCharacterList()
	{
		//use FileManager to get characters saved
		return NULL;
	}

#pragma region Character set and get methods

	DllExport int getIndex(char *name)
	{
		//do a search through the characters to get the index of that character
		return -1;
	}

	DllExport int setName(int index, char *name)
	{
		if (index >= characterCount)
			return -1;
		char *n = (char *)malloc(sizeof(char) * 32);
		strcpy_s(n, 32, name);
		(*characters[index]).setName(n);
		free(n);
		return 0;
	}

	DllExport int setStat(int index, int number, int stat)
	{
		if (index >= characterCount)
			return -1;
		switch (stat)
		{
		case 0:
			(*characters[index]).setStrength(number);
			break;
		case 1:
			(*characters[index]).setDexterity(number);
			break;
		case 2:
			(*characters[index]).setAgility(number);
			break;
		case 3:
			(*characters[index]).setConstitution(number);
			break;
		case 4:
			(*characters[index]).setIntellect(number);
			break;
		case 5:
			(*characters[index]).setWillpower(number);
			break;
		case 6:
			(*characters[index]).setPerception(number);
			break;
		case 7:
			(*characters[index]).setCommunication(number);
			break;
		case 8:
			(*characters[index]).setBeauty(number);
			break;
		default:
			break;
		}
		return 0;
	}

	DllExport int setBirth(int index, int date, int ymd)
	{
		if (index >= characterCount)
			return -1;
		if (ymd == 0)
			(*characters[index]).setYears(date);
		if (ymd == 1)
			(*characters[index]).setDays(date);
		if (ymd == 2)
			(*characters[index]).setSeconds(date);
		return 0;
	}

	DllExport int setBaseHeight(int index, float h)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setHeight(h);
		return 0;
	}

	DllExport int setBaseWeight(int index, float w)
	{
		if (index >= characterCount)
			return -1;
		(*characters[index]).setWeight(w);
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

	DllExport float getStat(int index, int stat, int type)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getStat(stat, type);
	}

	DllExport int getTraining(int index, int stat)
	{
		if (index >= characterCount)
			return -1;
		return (*characters[index]).getDodge();
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
	}*/
}

#pragma endregion
