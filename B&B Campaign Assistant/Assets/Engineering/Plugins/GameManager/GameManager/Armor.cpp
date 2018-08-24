#include "Armor.h"

Armor::Armor(char *n, std::unordered_map<std::string, int *> bp) : Item()
{
	//armorData is the parsed and edited data from the .blade file to be set as defense
	name = n;
	defense = bp;
}

int Armor::getDefense(char *location, int hit, int *damageTypes)		//damage should be the length of all damage types in the ruleset (3 currently)
{
	//determines first which damage type exceeds the armor's defense the most
	//then reduces the hit by the difference between the armor's defense and the damage type
	//if the reduction would positively impact the hit, it is not applied
	int dif = 0;
	if (defense.find(std::string(location)) != defense.end)
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
