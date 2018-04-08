#include "Character.h"

Character::Character() : Entity()
{
	type = (char *)malloc(sizeof(char) * 6);
	strcpy(type, "human\0");
	hands = 2;
	hand = (char **)malloc(hands * sizeof(char *));
	//add randomness to handedness later
	hand[0] = (char *)malloc(5 * sizeof(char));
	strcpy(hand[0], "left\0");
	hand[1] = (char *)malloc(6 * sizeof(char));
	strcpy(hand[1], "right\0");
	weaponEquipped = new Weapon[2];
	strength = -1;
	dexterity = -1;
	agility = -1;
	constitution = -1;
	intellect = -1;
	willpower = -1;
	perception = -1;
	charisma = -1;
	beauty = -1;
}

Character::~Character()
{
	if (eyesight != NULL)
		free(eyesight);
}

void Character::setStrength(int s) { strength = s; }
void Character::setDexterity(int d) { dexterity = d; }
void Character::setAgility(int a) { agility = a; }
void Character::setConstitution(int c) { constitution = c; }
void Character::setIntellect(int i) { intellect = i; }
void Character::setWillpower(int w) { willpower = w; }
void Character::setPerception(int p) { perception = p; }
void Character::setCharisma(int c) { charisma = c; }
void Character::setBeauty(int b) { beauty = b; }
void Character::setBirth(int y, int d, int s) { years = y; days = d; seconds = s; }
void Character::setBaseHeight(float h) { baseHeight = h; height = h; }
void Character::setBaseWeight(float w) { baseWeight = w; weight = w; }

bool Character::buildCharacter()
{
	if(strength != -1)
	{
		bool success = buildStrength();
	}
	if(dexterity != -1)
	{
		bool success = buildDexterity();
	}
	if(agility != -1)
	{
		bool success = buildAgility();
	}
	if(constitution != -1)
	{
		bool success = buildConstitution();
	}
	if(willpower != -1)
	{
		bool success = buildWillpower();
	}
	if(perception != -1)
	{
		bool success = buildPerception();
	}
	if (intellect != -1)
	{

	}
	if(charisma != -1)
	{
		
	}
	if(beauty != -1)
	{
		
	}
}

bool Character::buildStrength()
{
	restrictMax = strength;
	restrict = 0;
	carry = 0;
	switch (strength)
	{
		case 1: damageBonus = -4; carryMax = 5; liftMax = 20; break;
		case 2: damageBonus = -2; carryMax = 10; liftMax = 30; break;
		case 3: damageBonus = -1; carryMax = 20; liftMax = 50; break;
		case 4: damageBonus = 0; carryMax = 30; liftMax = 70; break;
		case 5: damageBonus = 0; carryMax = 30; liftMax = 80; break;
		case 6: damageBonus = 0; carryMax = 30; liftMax = 90; break;
		case 7: damageBonus = 0; carryMax = 35; liftMax = 100; break;
		case 8: damageBonus = 0; carryMax = 35; liftMax = 110; break;
		case 9: damageBonus = 0; carryMax = 40; liftMax = 120; break;
		case 10: damageBonus = 0; carryMax = 45; liftMax = 140; break;
		case 11: damageBonus = 0; carryMax = 45; liftMax = 160; break;
		case 12: damageBonus = 1; carryMax = 50; liftMax = 200; break;
		case 13: damageBonus = 1; carryMax = 55; liftMax = 250; break;
		case 14: damageBonus = 2; carryMax = 60; liftMax = 320; break;
		case 15: damageBonus = 2; carryMax = 70; liftMax = 400; break;
		case 16: damageBonus = 3; carryMax = 90; liftMax = 500; break;
		case 17: damageBonus = 3; carryMax = 120; liftMax = 620; break;
		case 18: damageBonus = 4; carryMax = 150; liftMax = 750; break;
		default: return false;
	}
	return true;
}

bool Character::buildDexterity()
{
	switch (dexterity)
	{
		case 1: weaponProficiency = -5; break;
		case 2: weaponProficiency = -4; break;
		case 3: weaponProficiency = -3; break;
		case 4: weaponProficiency = -2; break;
		case 5: weaponProficiency = -1; break;
		case 6: weaponProficiency = -1; break;
		case 7: weaponProficiency = 0; break;
		case 8: weaponProficiency = 0; break;
		case 9: weaponProficiency = 0; break;
		case 10: weaponProficiency = 0; break;
		case 11: weaponProficiency = 0; break;
		case 12: weaponProficiency = 1; break;
		case 13: weaponProficiency = 1; break;
		case 14: weaponProficiency = 2; break;
		case 15: weaponProficiency = 2; break;
		case 16: weaponProficiency = 3; break;
		case 17: weaponProficiency = 3; break;
		case 18: weaponProficiency = 4; break;
	default: return false;
	}
	return true;
}

bool Character::buildAgility()
{
	switch (agility)
	{
		case 1: initiativeBase = 4; defenseBase = -4; walkSpeed = 2; combatSpeed = 10; runSpeed = 20; travelSpeed = 3; break;
		case 2: initiativeBase = 3; defenseBase = -3; walkSpeed = 4; combatSpeed = 20; runSpeed = 30; travelSpeed = 6; break;
		case 3: initiativeBase = 2; defenseBase = -2; walkSpeed = 6; combatSpeed = 20; runSpeed = 40; travelSpeed = 12; break;
		case 4: initiativeBase = 2; defenseBase = -2; walkSpeed = 6; combatSpeed = 20; runSpeed = 45; travelSpeed = 12; break;
		case 5: initiativeBase = 1; defenseBase = -1; walkSpeed = 12; combatSpeed = 30; runSpeed = 45; travelSpeed = 20; break;
		case 6: initiativeBase = 1; defenseBase = -1; walkSpeed = 12; combatSpeed = 30; runSpeed = 50; travelSpeed = 20; break;
		case 7: initiativeBase = 1; defenseBase = -1; walkSpeed = 15; combatSpeed = 30; runSpeed = 50; travelSpeed = 24; break;
		case 8: initiativeBase = 1; defenseBase = -1; walkSpeed = 15; combatSpeed = 30; runSpeed = 50; travelSpeed = 24; break;
		case 9: initiativeBase = 0; defenseBase = 0; walkSpeed = 15; combatSpeed = 30; runSpeed = 50; travelSpeed = 24; break;
		case 10: initiativeBase = 0; defenseBase = 0; walkSpeed = 15; combatSpeed = 30; runSpeed = 50; travelSpeed = 24; break;
		case 11: initiativeBase = 0; defenseBase = 0; walkSpeed = 15; combatSpeed = 30; runSpeed = 50; travelSpeed = 24; break;
		case 12: initiativeBase = 0; defenseBase = 0; walkSpeed = 15; combatSpeed = 30; runSpeed = 50; travelSpeed = 24; break;
		case 13: initiativeBase = -1; defenseBase = 1; walkSpeed = 15; combatSpeed = 30; runSpeed = 55; travelSpeed = 24; break;
		case 14: initiativeBase = -1; defenseBase = 2; walkSpeed = 16; combatSpeed = 30; runSpeed = 55; travelSpeed = 28; break;
		case 15: initiativeBase = -1; defenseBase = 3; walkSpeed = 18; combatSpeed = 35; runSpeed = 60; travelSpeed = 32; break;
		case 16: initiativeBase = -2; defenseBase = 4; walkSpeed = 20; combatSpeed = 40; runSpeed = 70; travelSpeed = 36; break;
		case 17: initiativeBase = -2; defenseBase = 6; walkSpeed = 21; combatSpeed = 45; runSpeed = 80; travelSpeed = 38; break;
		case 18: initiativeBase = -3; defenseBase = 7; walkSpeed = 24; combatSpeed = 50; runSpeed = 90; travelSpeed = 40; break;
	default: return false;
	}
	initiative = initiativeBase;
	return true;
}

bool Character::buildConstitution()
{
	overheatMax = constitution;
	overheat = 0;
	healthMax = constitution;
	health = healthMax;
	healSpeed = (float)(constitution) / 10;
}

bool Character::buildWillpower()
{
	resolve = willpower;
	switch (willpower)
	{
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
}

bool Character::buildPerception()
{
	switch (perception)
	{
	case 1: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Blind"); eyeglassesBonus = 5; break;
	case 2: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Legally Blind"); eyeglassesBonus = 4; break;
	case 3: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Legally Blind"); eyeglassesBonus = 3; break;
	case 4: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Bad"); eyeglassesBonus = 2; break;
	case 5: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Bad"); eyeglassesBonus = 2; break;
	case 6: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 7: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 8: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 9: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 10: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 11: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 12: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 13: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Normal"); eyeglassesBonus = 1; break;
	case 14: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Good"); eyeglassesBonus = 0; break;
	case 15: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Good"); eyeglassesBonus = 0; break;
	case 16: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Good"); eyeglassesBonus = 0; break;
	case 17: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Good"); eyeglassesBonus = 0; break;
	case 18: eyesight = (char *)malloc(sizeof(char) * 32); strcpy(eyesight, "Good"); eyeglassesBonus = 0; break;
	default: return false;
	}
}

int Character::getStrength() { return strength; }
int Character::getDexterity() { return dexterity; }
int Character::getAgility() { return agility; }
int Character::getConstitution() { return constitution; }
int Character::getIntellect() { return intellect; }
int Character::getWillpower() { return willpower; }
int Character::getPerception() { return perception; }
int Character::getCharisma() { return charisma; }
int Character::getBeauty() { return beauty; }

int Character::getRestrictMax() { return restrictMax; }
int Character::getRestrict() { return restrict; }
int Character::getOverheatMax() { return overheatMax; }
int Character::getOverheat() { return overheat; }
int Character::getDamageBonus() { return damageBonus; }
int Character::getCarryMax() { return carryMax; }
float Character::getCarry() { return carry; }
int Character::getLiftMax() { return liftMax; }
int Character::getWeaponProficiency() { return weaponProficiency; }
int Character::getInitiativeBase() { return initiativeBase; }
int Character::getInitiative() { return initiative; }
int Character::getDefenseBase() { return defenseBase; }
int Character::getDefense() { return defense; }
int Character::getHealthMax() { return healthMax; }
float Character::getHealth() { return health; }
float Character::getHealSpeed() { return healSpeed; }
float Character::getBaseWeight() { return baseWeight; }
float Character::getBaseHeight() { return baseHeight; }
float Character::getWeight() { return weight; }
float Character::getHeight() { return height; }
int Character::getResolve() { return resolve; }
int Character::getSorceryBonus() { return sorceryBonus; }
int Character::getEyeglassesBonus() { return eyeglassesBonus; }
char *Character::getEyesight() { return eyesight; }