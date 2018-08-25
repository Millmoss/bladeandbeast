#include <iostream>
#include <filesystem>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include "Armor.h"

class DataManager
{
public:
	DataManager();
	Armor createArmor(const char *f);
	~DataManager();
private:
	std::unordered_map<std::string, std::string> dataFiles;	//map of object names to file names
	std::unordered_map<std::string, std::string[]> dataGroupings; //map of object groups to objects in that group
};
