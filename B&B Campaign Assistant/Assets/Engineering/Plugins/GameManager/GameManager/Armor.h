#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include "Item.h"

#ifndef __ARMOR_H_INCLUDED__
#define __ARMOR_H_INCLUDED__

class Armor : Item
{
public:
	Armor(char *n, std::unordered_map<std::string, int *> bp);
	int getDefense(char *location, int hit, int *damageTypes);	//gets the damage reduction on the attack
protected:
	std::unordered_map<std::string, int *> defense;
	int damageTypeCount;
	//defense contains keys listing every body part the armor covers and the defense of that part against a certain damage type
	//these damage types can technically be anything, but in the case of this ruleset:
	//0 is cut damage, 1 is crush damage, and 2 is stab damage
};

#endif
