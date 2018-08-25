#include "DataManager.h"

DataManager::DataManager()
{
	FILE *file;
	char *armorPath = (char *)malloc(sizeof(char) * 64);
	char *weaponsPath = (char *)malloc(sizeof(char) * 64);
	char *miscPath = (char *)malloc(sizeof(char) * 64);
	char *charactersPath = (char *)malloc(sizeof(char) * 64);
	char *path = (char *)malloc(sizeof(char) * 128);
	//char *name = characters[index]->getName();
	sprintf_s(armorPath, 64, "Blade&BeastData\\Items\\Armor");
	sprintf_s(weaponsPath, 64, "Blade&BeastData\\Items\\Weapons");
	sprintf_s(miscPath, 64, "Blade&BeastData\\Items\\Misc");
	sprintf_s(charactersPath, 64, "Blade&BeastData\\Characters");
	sprintf_s(path, 128, "Blade&BeastSaves\\Characters\\out.txt");
	fopen_s(&file, path, "w");
	for (auto& p : std::filesystem::directory_iterator(armorPath))
	{
		const char *f = p.path().string().c_str();
		fprintf_s(file, "%s\n", f);
		Armor m = createArmor(f);
		//m.writeTo(file);
	}
	for (auto& p : std::filesystem::directory_iterator(weaponsPath))
		fprintf_s(file, "%s\n", p.path().string().c_str());
	for (auto& p : std::filesystem::directory_iterator(miscPath))
		fprintf_s(file, "%s\n", p.path().string().c_str());
	for (auto& p : std::filesystem::directory_iterator(charactersPath))
		fprintf_s(file, "%s\n", p.path().string().c_str());
	fclose(file);
	free(armorPath);
	free(weaponsPath);
	free(miscPath);
	free(charactersPath);
	free(path);
}

Armor DataManager::createArmor(const char *f)
{
	FILE *aFile;
	fopen_s(&aFile, f, "r");
	
	//char *n = NULL;
	//float w;
	//float p;
	//float dur;
	//int dtc = -1;
	//std::string part;
	//std::unordered_map<std::string, int *> def;

	int c;
	//int entry = 0;
	int a = 0;
	if (aFile)
	while ((c = fgetc(aFile)) != EOF)
	{
		/*char ch = c;
		if (c == '[')
		{
			char *data = (char *)malloc(sizeof(char) * 128);
			int pos = 0;
			while ((c = fgetc(aFile)) != ']')
			{
				if (c == EOF)
				{
					fclose(aFile);
					return Armor();
				}
				data[pos] = c;
				pos++;
			}
			if (entry == 0)
				n = data;
			else if (entry == 1)
				w = atof(data);
			else if (entry == 2)
				p = atof(data);
			else if (entry == 3)
				dur = atof(data);
			else if (entry % 2 == 0)
				part = std::string(data);
			else
			{
				char *token;
				char *next;
				token = strtok_s(data, ",", &next);
				int *din;
				int dpos = 0;
				if (dtc == -1)
				{
					dtc = 0;
					while (token)
					{
						puts(token);
						token = strtok_s(NULL, ",", &next);
						dpos++;
					}
					dtc = dpos;
					dpos = 0;
				}
				token = strtok_s(data, ",", &next);
				din = (int *)malloc(sizeof(int) * dtc);
				while (token)
				{
					din[dpos] = atoi(token);
					token = strtok_s(NULL, ",", &next);
					dpos++;
				}
				def[part] = din;
			}
			free(data);
		}
		entry++;*/
	}
	fclose(aFile);
	//return Armor(n, w, p, dur, dtc, def);
	return Armor();
}

DataManager::~DataManager()
{
}
