#include <iostream>
#include <filesystem>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include "Wearable.h"
#include "Weapon.h"
#include "Character.h"

#ifndef __DATAMANAGER_H_INCLUDED__
#define __DATAMANAGER_H_INCLUDED__

class DataManager
{
public:
	DataManager();
	Character createCharacter(const char *f);
	Wearable createWearable(const char *f);
	Weapon createWeapon(const char *f);
	Item createMisc(const char *f);
	~DataManager();
private:
	std::unordered_map<std::string, std::string> dataFiles;	//map of object names to file names
	std::unordered_map<std::string, std::string[]> dataGroupings; //map of object groups to objects in that group
};

#endif
