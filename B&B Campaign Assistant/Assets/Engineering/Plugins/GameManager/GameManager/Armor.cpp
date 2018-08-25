#include "Armor.h"

Armor::Armor() : Item()
{
	name = NULL;
	description = NULL;
}

Armor::Armor(char *n, float w, float p, float dur, char *desc, int dtc, std::unordered_map<std::string, int *> def) : Item()
{
	//armorData is the parsed and edited data from the .blade file to be set as defense
	name = n;
	weight = w;
	price = p;
	durability = dur;
	description = desc;
	damageTypeCount = dtc;
	defense = def;
}

int Armor::getDefense(char *location, int hit, int *damageTypes)		//damage should be the length of all damage types in the ruleset (3 currently)
{
	//determines first which damage type exceeds the armor's defense the most
	//then reduces the hit by the difference between the armor's defense and the damage type
	//if the reduction would positively impact the hit, it is not applied
	int dif = 0;
	if (defense.find(std::string(location)) != defense.end())
	{
		int hi = 0;
		for (int i = 0; i < damageTypeCount; i++)
		{
			if (damageTypes[i] + hit - defense[std::string(location)][i] > damageTypes[hi] + hit - defense[std::string(location)][hi])
				dif = i;
		}
		dif = damageTypes[hi] + hit - defense[std::string(location)][hi];
		if (dif < 0)
			dif = 0;
	}
	return dif;
}

void Armor::writeTo(FILE *f)
{
	for (unsigned i = 0; i < defense.bucket_count(); ++i)
	for (auto local_it = defense.begin(i); local_it != defense.end(i); ++local_it)
	{
		fprintf_s(f, "%s\n", (local_it->first).c_str());
		fprintf_s(f, "%d, %d, %d\n", defense[local_it->first][0], defense[local_it->first][1], defense[local_it->first][2]);
	}
}

Armor::~Armor()
{
	if (name != NULL)
		free(name);
	if (description != NULL)
		free(description);
}
