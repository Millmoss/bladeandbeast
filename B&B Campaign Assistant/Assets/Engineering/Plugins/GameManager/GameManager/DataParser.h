#include <iostream>
#include <stdlib.h>
#include <unordered_map>

class DataParser
{
public:
	DataParser();
	~DataParser();
private:
	std::unordered_map<std::string, std::string> dataFiles;	//map of object names to file names
	std::unordered_map<std::string, std::string[]> dataGroupings; //map of object groups to objects in that group
};
