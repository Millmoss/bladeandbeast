#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include "Item.h"

#ifndef __WEARABLE_H_INCLUDED__
#define __WEARABLE_H_INCLUDED__

class Wearable : Item
{
public:
	Wearable();
	Wearable(std::string n, std::string type, float w, float p, float dur, std::string desc, int dtc, std::unordered_map<std::string, int *> def);
	int getDefense(std::string location, int hit, int *damageTypes);	//gets the damage reduction on the attack
	void writeTo(FILE *f);
	~Wearable();
protected:
	std::string type;													//the type of the wearable: Armor, Clothing, Container, Adornment
	std::unordered_map<std::string, int *> defense;						//even if it's not armor, it still gives defense
	//defense contains keys listing every body part the wearable covers and the defense of that part against a certain damage type
	//these damage types can technically be anything, but in the case of this ruleset:
	//0 is cut damage, 1 is crush damage, and 2 is stab damage
	float restrict;														//how restrictive the item is
	float overheat;														//how much the item causes the wearer to retain heat
	int damageTypeCount;												//possible this should be more global
	float xWeightDistribution;											//these three determine the distribution of weight from the person's center
	float yWeightDistribution;											//if all are 0, weight is perfectly distributed
	float zWeightDistribution;											//if x is -0.25, all the weight is distributed a three inches behind the person
};

#endif
