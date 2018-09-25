#include "Character.h"

Character::Character() : Being()
{
	type = (char *)malloc(sizeof(char) * 6);
	strcpy_s(type, sizeof(6 * sizeof(char)), "human\0");
	hands = 2;
	hand = (char **)malloc(hands * sizeof(char *));
	hand[0] = (char *)malloc(5 * sizeof(char));
	strcpy_s(hand[0], sizeof(5 * sizeof(char)), "left\0");
	hand[1] = (char *)malloc(6 * sizeof(char));
	strcpy_s(hand[1], sizeof(6 * sizeof(char)), "right\0");
	weaponEquipped = new Weapon[2];
	strength = -1;
	strengthMod = 0;
	dexterity = -1;
	dexterityMod = 0;
	agility = -1;
	agilityMod = 0;
	constitution = -1;
	constitutionMod = 0;
	intellect = -1;
	intellectMod = 0;
	willpower = -1;
	willpowerMod = 0;
	perception = -1;
	perceptionMod = 0;
	charisma = -1;
	charismaMod = 0;
	beauty = -1;
	beautyMod = 0;
	years = -1;
	days = -1;
	seconds = -1;
	restrictMax = -1;
	restrictMaxMod = 0;
	restrict = 0;
	overheatMax = -1;
	overheatMaxMod = 0;
	overheat = 0;
	carryMax = -1;
	carryMaxMod = 0;
	carry = 0;
	liftMax = -1;
	liftMaxMod = 0;
	proficiencyPoints = -1;
	speed = -1;
	speedMod = 0;
	healthMax = -1;
	healthMaxMod = 0;
	health = 0;
	healthMod = 0;
	healRate = -1;
	healRateMod = -1;
	weight = -1;
	height = -1;
	weightMod = 0;
	heightMod = 0;
	resolve = -1;
	resolveMod = 0;
	sorceryBonus = -1;
	sorceryBonusMod = 0;
	eyeglassesBonus = -1;
	eyeglassesBonusMod = 0;
	eyesight = (char *)malloc(sizeof(char) * 16);
	strcpy_s(eyesight, 16, "Unknown");
}

Character::~Character()
{
	if (eyesight != NULL)
		free(eyesight);
}

void Character::setStrength(int s) { strength = s; restrictMax = s; }
void Character::setDexterity(int d) { dexterity = d; }
void Character::setAgility(int a) { agility = a; }
void Character::setConstitution(int c) { constitution = c; float h = health; healthMax = c; health = h; overheatMax = c; healRate = ((float)c) / 10; }
void Character::setIntellect(int i) { intellect = i; }
void Character::setWillpower(int w) { willpower = w; resolve = w; }
void Character::setPerception(int p) { perception = p; }
void Character::setCharisma(int c) { charisma = c; }
void Character::setBeauty(int b) { beauty = b; }
void Character::setYears(int y) { years = y; }
void Character::setDays(int d) { days = d; }
void Character::setSeconds(int s) { seconds = s; }
void Character::setHeight(float h) { height = h; heightMod = h; }
void Character::setWeight(float w) { weight = w; weightMod = w; }

bool Character::buildCharacter()
{
	bool totalSuccess = true;
	if(carryMax == -1)
	{
		bool success = buildCarry();
		totalSuccess = (totalSuccess && success);
	}
	if(speed == -1)
	{
		bool success = buildAgilityStats();
		totalSuccess = (totalSuccess && success);
	}
	if(eyeglassesBonus == -1)
	{
		bool success = buildEyesight();
		totalSuccess = (totalSuccess && success);
	}
	if(sorceryBonus == -1)
	{
		bool success = buildSorcery();
		totalSuccess = (totalSuccess && success);
	}
	if (proficiencyPoints == -1)
	{
		bool success = buildProficiency();
		totalSuccess = (totalSuccess && success);
	}
	return totalSuccess;
}

bool Character::buildCarry()
{
	restrictMax = strength;
	restrict = 0;
	carry = 0;
	switch (strength)
	{//FIX THIS
		case 1: carryMax = 5; liftMax = 20; break;
		case 2: carryMax = 10; liftMax = 30; break;
		case 3: carryMax = 20; liftMax = 50; break;
		case 4: carryMax = 30; liftMax = 70; break;
		case 5: carryMax = 30; liftMax = 80; break;
		case 6: carryMax = 30; liftMax = 90; break;
		case 7: carryMax = 35; liftMax = 100; break;
		case 8:  carryMax = 35; liftMax = 110; break;
		case 9: carryMax = 40; liftMax = 120; break;
		case 10: carryMax = 45; liftMax = 140; break;
		case 11: carryMax = 45; liftMax = 160; break;
		case 12: carryMax = 50; liftMax = 200; break;
		case 13: carryMax = 55; liftMax = 250; break;
		case 14: carryMax = 60; liftMax = 320; break;
		case 15: carryMax = 70; liftMax = 400; break;
		case 16: carryMax = 90; liftMax = 500; break;
		case 17: carryMax = 120; liftMax = 620; break;
		case 18: carryMax = 150; liftMax = 750; break;
		default: return false;
	}
	return true;
}

bool Character::buildEyesight()
{
	switch (perception)
	{//FIX THIS
	case 1: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 6, "Blind"); eyeglassesBonus = 5; break;
	case 2: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 14, "Legally Blind"); eyeglassesBonus = 4; break;
	case 3: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 14, "Legally Blind"); eyeglassesBonus = 3; break;
	case 4: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 4, "Bad"); eyeglassesBonus = 2; break;
	case 5: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 4, "Bad"); eyeglassesBonus = 2; break;
	case 6: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 7: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 8: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 9: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 10: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 11: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 12: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 13: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 7, "Normal"); eyeglassesBonus = 1; break;
	case 14: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 5, "Good"); eyeglassesBonus = 0; break;
	case 15: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 5, "Good"); eyeglassesBonus = 0; break;
	case 16: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 5, "Good"); eyeglassesBonus = 0; break;
	case 17: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 5, "Good"); eyeglassesBonus = 0; break;
	case 18: eyesight = (char *)malloc(sizeof(char) * 32); strcpy_s(eyesight, sizeof(char) * 5, "Good"); eyeglassesBonus = 0; break;
	default: return false;
	}
	return true;
}

bool Character::buildSorcery()
{
	switch (willpower)
	{//FIX THIS
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		case 7: break;
		case 8: break;
		case 9: break;
		case 10: break;
		case 11: break;
		case 12: sorceryBonus = 1; break;
		case 13: sorceryBonus = 1; break;
		case 14: sorceryBonus = 2; break;
		case 15: sorceryBonus = 2; break;
		case 16: sorceryBonus = 3; break;
		case 17: sorceryBonus = 3; break;
		case 18: sorceryBonus = 4; break;
		default: return false;
	}
	return true;
}

bool Character::buildAgilityStats()
{
	switch (agility)
	{//FIX THIS
		case 1: speed = 4; dodge = -4; walkMove = 2; combatMove = 10; runMove = 20; travelMove = 3; break;
		case 2: speed = 3; dodge = -3; walkMove = 4; combatMove = 20; runMove = 30; travelMove = 6; break;
		case 3: speed = 2; dodge = -2; walkMove = 6; combatMove = 20; runMove = 40; travelMove = 12; break;
		case 4: speed = 2; dodge = -2; walkMove = 6; combatMove = 20; runMove = 45; travelMove = 12; break;
		case 5: speed = 1; dodge = -1; walkMove = 12; combatMove = 30; runMove = 45; travelMove = 20; break;
		case 6: speed = 1; dodge = -1; walkMove = 12; combatMove = 30; runMove = 50; travelMove = 20; break;
		case 7: speed = 1; dodge = -1; walkMove = 15; combatMove = 30; runMove = 50; travelMove = 24; break;
		case 8: speed = 1; dodge = -1; walkMove = 15; combatMove = 30; runMove = 50; travelMove = 24; break;
		case 9: speed = 0; dodge = 0; walkMove = 15; combatMove = 30; runMove = 50; travelMove = 24; break;
		case 10: speed = 0; dodge = 0; walkMove = 15; combatMove = 30; runMove = 50; travelMove = 24; break;
		case 11: speed = 0; dodge = 0; walkMove = 15; combatMove = 30; runMove = 50; travelMove = 24; break;
		case 12: speed = 0; dodge = 0; walkMove = 15; combatMove = 30; runMove = 50; travelMove = 24; break;
		case 13: speed = -1; dodge = 1; walkMove = 15; combatMove = 30; runMove = 55; travelMove = 24; break;
		case 14: speed = -1; dodge = 2; walkMove = 16; combatMove = 30; runMove = 55; travelMove = 28; break;
		case 15: speed = -1; dodge = 3; walkMove = 18; combatMove = 35; runMove = 60; travelMove = 32; break;
		case 16: speed = -2; dodge = 4; walkMove = 20; combatMove = 40; runMove = 70; travelMove = 36; break;
		case 17: speed = -2; dodge = 6; walkMove = 21; combatMove = 45; runMove = 80; travelMove = 38; break;
		case 18: speed = -3; dodge = 7; walkMove = 24; combatMove = 50; runMove = 90; travelMove = 40; break;
		default: return false;
	}
	return true;
}

char *Character::getName() { return name; }
int Character::getStrength() { return strength; }
int Character::getDexterity() { return dexterity; }
int Character::getAgility() { return agility; }
int Character::getConstitution() { return constitution; }
int Character::getIntellect() { return intellect; }
int Character::getWillpower() { return willpower; }
int Character::getPerception() { return perception; }
int Character::getCharisma() { return charisma; }
int Character::getBeauty() { return beauty; }
char *Character::getAge() { char *r = (char *)malloc(sizeof(char) * 32); sprintf_s(r, 32, "WOAH"); return r; }

int Character::getRestrictMax() { return restrictMax; }
int Character::getRestrictMaxMod() { return restrictMaxMod; }
int Character::getRestrict() { return restrict; }
int Character::getOverheatMax() { return overheatMax; }
int Character::getOverheatMaxMod() { return overheatMaxMod; }
int Character::getOverheat() { return overheat; }
int Character::getCarryMax() { return carryMax; }
int Character::getCarryMaxMod() { return carryMaxMod; }
float Character::getCarry() { return carry; }
int Character::getLiftMax() { return liftMax; }
int Character::getLiftMaxMod() { return liftMaxMod; }
int Character::getProficiencyPoints() { return proficiencyPoints; }
int Character::getSpeed() { return speed; }
int Character::getSpeedMod() { return speedMod; }
int Character::getDodge() {	return dodge; }
int Character::getDodgeMod() { return dodgeMod; }
int Character::getHealthMax() { return healthMax; }
int Character::getHealthMaxMod() { return healthMaxMod; }
float Character::getHealth() { return health; }
float Character::getHealthMod() { return healthMod; }
float Character::getHealRate() { return healRate; }
float Character::getHealRateMod() { return healRateMod; }
float Character::getHeight() { return height; }
float Character::getHeightMod() { return heightMod; }
float Character::getWeight() { return weight; }
float Character::getWeightMod() { return weightMod; }
int Character::getResolve() { return resolve; }
int Character::getResolveMod() { return resolveMod; }
int Character::getSorceryBonus() { return sorceryBonus; }
int Character::getSorceryBonusMod() { return sorceryBonusMod; }
int Character::getEyeglassesBonus() { return eyeglassesBonus; }
int Character::getEyeglassesBonusMod() { return eyeglassesBonusMod; }
char *Character::getEyesight() { return eyesight; }