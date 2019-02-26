#include "DataManager.h"

DataManager::DataManager()
{
	/*FILE *file;
	char *armorPath = (char *)malloc(sizeof(char) * 64);
	char *weaponsPath = (char *)malloc(sizeof(char) * 64);
	char *miscPath = (char *)malloc(sizeof(char) * 64);
	char *charactersPath = (char *)malloc(sizeof(char) * 64);
	char *path = (char *)malloc(sizeof(char) * 128);
	sprintf_s(armorPath, 64, "Blade&BeastData\\Items\\Armor");
	sprintf_s(weaponsPath, 64, "Blade&BeastData\\Items\\Weapons");
	sprintf_s(miscPath, 64, "Blade&BeastData\\Items\\Misc");
	sprintf_s(charactersPath, 64, "Blade&BeastData\\Characters");
	sprintf_s(path, 128, "Blade&BeastSaves\\Characters\\out.txt");
	fopen_s(&file, path, "w");
	for (auto& p : std::filesystem::directory_iterator(armorPath))
	{
		fprintf_s(file, "%s\n", p.path().string().c_str());
		Armor m = createArmor(p.path().string().c_str());
		m.writeTo(file);
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
	free(path);*/
}

/*Wearable DataManager::createWearable(const char *f)
{
	FILE *aFile;
	fopen_s(&aFile, f, "r");
	
	char *n = (char *)malloc(sizeof(char) * 64);
	float w;
	float p;
	float dur;
	char *desc = (char *)malloc(sizeof(char) * 256);
	int dtc = -1;
	std::string part;
	std::unordered_map<std::string, int *> def;

	int c;
	int entry = 0;
	int a = 0;
	if (aFile)
	{
		while ((c = fgetc(aFile)) != EOF)
		{
			char ch = c;
			if (c == '[')
			{
				char *data = (char *)malloc(sizeof(char) * 256);
				int pos = 0;
				while ((c = fgetc(aFile)) != ']' && pos < 255)
				{
					if (c == EOF)
					{
						fclose(aFile);
						return Armor();
					}
					data[pos] = c;
					pos++;
				}
				data[pos] = '\0';
				if (entry == 0)
				{
					data[63] = '\0';
					strcpy_s(n, 64, data);
				}
				else if (entry == 1)
					w = atof(data);
				else if (entry == 2)
					p = atof(data);
				else if (entry == 3)
					dur = atof(data);
				else if (entry == 4)
					strcpy_s(desc, 256, data);
				else if (entry % 2 == 1)
					part = std::string(data);
				else
				{
					int *din;
					int dpos = 0;
					if (dtc == -1)
					{
						int count = 1;
						for (int i = 0; i < pos; i++)
						{
							if (data[i] == ',')
								count++;
						}
						dtc = count;
					}
					din = (int *)malloc(sizeof(int) * dtc);
					char *numin = (char *)malloc(sizeof(char) * 32);
					int numincount = 0;
					int dincount = 0;
					for (int i = 0; i < pos; i++)
					{
						if (data[i] == ',' || i == pos - 1)
						{
							if (i == pos - 1)
							{
								numin[numincount] = data[i];
								numincount++;
							}
							numin[numincount] = '\0';
							din[dincount] = atoi(numin);
							dincount++;
							numincount = 0;
						}
						else
						{
							numin[numincount] = data[i];
							numincount++;
						}
					}
					def[part] = din;
				}
				free(data);
				entry++;
			}
		}
		fclose(aFile);
		return Armor(n, w, p, dur, desc, dtc, def);
	}
	else
		return Armor();
}*/

Weapon DataManager::createWeapon(const char *f)
{
	FILE *aFile;
	fopen_s(&aFile, f, "r");

	char *n = (char *)malloc(sizeof(char) * 64);
	float w;
	float p;
	float dur;
	char *desc = (char *)malloc(sizeof(char) * 256);
	int dtc = -1;
	std::string part;
	std::unordered_map<std::string, int *> def;

	int c;
	int entry = 0;
	int a = 0;
	if (aFile)
	{
		while ((c = fgetc(aFile)) != EOF)
		{
			char ch = c;
			if (c == '[')
			{
				char *data = (char *)malloc(sizeof(char) * 256);
				int pos = 0;
				while ((c = fgetc(aFile)) != ']' && pos < 255)
				{
					if (c == EOF)
					{
						fclose(aFile);
						return Weapon();
					}
					data[pos] = c;
					pos++;
				}
				data[pos] = '\0';
				if (entry == 0)
				{
					data[63] = '\0';
					strcpy_s(n, 64, data);
				}
				else if (entry == 1)
					w = atof(data);
				else if (entry == 2)
					p = atof(data);
				else if (entry == 3)
					dur = atof(data);
				else if (entry == 4)
					strcpy_s(desc, 256, data);
				else if (entry % 2 == 1)
					part = std::string(data);
				else
				{
					int *din;
					int dpos = 0;
					if (dtc == -1)
					{
						int count = 1;
						for (int i = 0; i < pos; i++)
						{
							if (data[i] == ',')
								count++;
						}
						dtc = count;
					}
					din = (int *)malloc(sizeof(int) * dtc);
					char *numin = (char *)malloc(sizeof(char) * 32);
					int numincount = 0;
					int dincount = 0;
					for (int i = 0; i < pos; i++)
					{
						if (data[i] == ',' || i == pos - 1)
						{
							if (i == pos - 1)
							{
								numin[numincount] = data[i];
								numincount++;
							}
							numin[numincount] = '\0';
							din[dincount] = atoi(numin);
							dincount++;
							numincount = 0;
						}
						else
						{
							numin[numincount] = data[i];
							numincount++;
						}
					}
					def[part] = din;
				}
				free(data);
				entry++;
			}
		}
		fclose(aFile);
		return Weapon();
	}
	else
		return Weapon();
}

Item DataManager::createMisc(const char *f)
{
	FILE *aFile;
	fopen_s(&aFile, f, "r");

	char *n = (char *)malloc(sizeof(char) * 64);
	float w;
	float p;
	float dur;
	char *desc = (char *)malloc(sizeof(char) * 256);
	int dtc = -1;
	std::string part;
	std::unordered_map<std::string, int *> def;

	int c;
	int entry = 0;
	int a = 0;
	if (aFile)
	{
		while ((c = fgetc(aFile)) != EOF)
		{
			char ch = c;
			if (c == '[')
			{
				char *data = (char *)malloc(sizeof(char) * 256);
				int pos = 0;
				while ((c = fgetc(aFile)) != ']' && pos < 255)
				{
					if (c == EOF)
					{
						fclose(aFile);
						return Item();
					}
					data[pos] = c;
					pos++;
				}
				data[pos] = '\0';
				if (entry == 0)
				{
					data[63] = '\0';
					strcpy_s(n, 64, data);
				}
				else if (entry == 1)
					w = atof(data);
				else if (entry == 2)
					p = atof(data);
				else if (entry == 3)
					dur = atof(data);
				else if (entry == 4)
					strcpy_s(desc, 256, data);
				else if (entry % 2 == 1)
					part = std::string(data);
				else
				{
					int *din;
					int dpos = 0;
					if (dtc == -1)
					{
						int count = 1;
						for (int i = 0; i < pos; i++)
						{
							if (data[i] == ',')
								count++;
						}
						dtc = count;
					}
					din = (int *)malloc(sizeof(int) * dtc);
					char *numin = (char *)malloc(sizeof(char) * 32);
					int numincount = 0;
					int dincount = 0;
					for (int i = 0; i < pos; i++)
					{
						if (data[i] == ',' || i == pos - 1)
						{
							if (i == pos - 1)
							{
								numin[numincount] = data[i];
								numincount++;
							}
							numin[numincount] = '\0';
							din[dincount] = atoi(numin);
							dincount++;
							numincount = 0;
						}
						else
						{
							numin[numincount] = data[i];
							numincount++;
						}
					}
					def[part] = din;
				}
				free(data);
				entry++;
			}
		}
		fclose(aFile);
		return Item();
	}
	else
		return Item();
}

DataManager::~DataManager()
{
}
