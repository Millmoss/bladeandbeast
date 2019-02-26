#include "Character.h"

Character::Character() : Being()
{
	type = "human";
	hands = 2;
	hand = new std::string[2];
	hand[0] = "left";
	hand[1] = "right";
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
	communication = -1;
	communicationMod = 0;
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
	/*carryMax = -1;
	carryMaxMod = 0;
	carry = 0;
	liftMax = -1;
	liftMaxMod = 0;*/
	statPoints = 0;
	skillPoints = -1;
	speed = -1;
	speedMod = 0;
	healthMax = -1;
	healthMaxMod = 0;
	health = 0;
	healthMod = 0;
	healRate = -1;
	healRateMod = -1;
	height = -1;
	heightMod = 0;
	weight = -1;
	weightMod = 0;
	resolve = -1;
	resolveMod = 0;
	sorceryBonus = -1;
	sorceryBonusMod = 0;
	eyeglassesBonus = -1;
	eyeglassesBonusMod = 0;
	eyesight = "Unknown";
	trainingStrength = 0;
	hoursStrength = std::deque<float>();
	trainingDexterity = 0;
	hoursDexterity = std::deque<float>();
	trainingAgility = 0;
	hoursAgility = std::deque<float>();
	trainingConstitution = 0;
	hoursConstitution = std::deque<float>();
	trainingIntellect = 0;
	trainingIntellectMin = 0;
	hoursIntellect = std::deque<float>();
	trainingWillpower = 0;
	trainingWillpowerMin = 0;
	hoursWillpower = std::deque<float>();
	trainingPerception = 0;
	trainingPerceptionMin = 0;
	hoursPerception = std::deque<float>();
	trainingCommunication = 0;
	trainingCommunicationMin = 0;
	hoursCommunication = std::deque<float>();
	trainingBeauty = 0;
	trainingBeautyMin = 0;
	hoursBeauty = std::deque<float>();
	strengthPotential = 0;
	strengthTendency = 0;
	dexterityPotential = 0;
	dexterityTendency = 0;
	agilityPotential = 0;
	agilityTendency = 0;
	constitutionPotential = 0;
	constitutionTendency = 0;
	intellectPotential = 0;
	intellectTendency = 0;
	willpowerPotential = 0;
	willpowerTendency = 0;
	perceptionPotential = 0;
	perceptionTendency = 0;
	communicationPotential = 0;
	communicationTendency = 0;
	beautyPotential = 0;
	beautyTendency = 0;
	statPointsBonus = 0;
	upperHeight = 0;
	lowerHeight = 0;
	bmiLowStandard = 0;
	bmiHighStandard = 0;
}

Character::~Character()
{

}

void Character::setStrength(int s) { strength = s; restrictMax = s; }
void Character::setDexterity(int d) { dexterity = d; }
void Character::setAgility(int a) { agility = a; }
void Character::setConstitution(int c) { constitution = c; float h = healthMax; healthMax = c; health += healthMax - h; overheatMax = c; healRate = ((float)c) / 10; }
void Character::setIntellect(int i) { intellect = i; }
void Character::setWillpower(int w) { willpower = w; resolve = w; }
void Character::setPerception(int p) { perception = p; }
void Character::setCommunication(int c) { communication = c; }
void Character::setBeauty(int b) { beauty = b; }
void Character::setYears(int y) { years = y; }
void Character::setDays(int d) { days = d; }
void Character::setSeconds(int s) { seconds = s; }
void Character::setHeight(float h) { height = h; }
void Character::setWeight(float w) { weight = w; }

bool Character::buildCharacter()
{
	bool totalSuccess = true;
	/*if(carryMax == -1)	TOTO
	{
		bool success = buildCarry();
		totalSuccess = (totalSuccess && success);
	}*/
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
	if (skillPoints == -1)
	{
		//bool success = buildSkill();	TOTO
		//totalSuccess = (totalSuccess && success);
	}
	return totalSuccess;
}

bool Character::buildEyesight()
{
	switch (perception)
	{//FIX THIS
	case 1: eyesight = "Blind"; eyeglassesBonus = 5; break;
	case 18: eyesight = "Excellent"; eyeglassesBonus = 0; break;
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
		case 25: speed = -3; dodge = 7; walkMove = 24; combatMove = 50; runMove = 90; travelMove = 40; break;
		default: return false;
	}
	return true;
}

bool Character::buildWeightMod()
{
	bool success = true;
	weightMod = 0;
	if (strength != 0 && bmiHighStandard != 0 && bmiLowStandard != 0 && height != 0)
		weightMod += ((float)(strength + strengthMod) / (float)250) * (bmiHighStandard + bmiLowStandard) / (2 * 703) * height;

	return success;
}

bool Character::buildEquipLoad()
{
	//combat load sources
	//https://assets.publishing.service.gov.uk/government/uploads/system/uploads/attachment_data/file/455089/20150820-FOI06779_The_Soldiers_Load.pdf
	//https://www.globalsecurity.org/military/library/report/call/call_01-15_ch11.htm

	return false;
}

std::string Character::getName() { return name; }
float Character::getStat(int stat, int type)
{ 
	switch (stat)
	{
	case 0:
		if (type == 0)
			return strength;
		if (type == 1)
			return strengthMod;
		if (type == 2)
			return strengthPotential;
		if (type == 3)
			return strengthTendency;
		break;
	case 1:
		if (type == 0)
			return dexterity;
		if (type == 1)
			return dexterityMod;
		if (type == 2)
			return dexterityPotential;
		if (type == 3)
			return dexterityTendency;
		break;
	case 2:
		if (type == 0)
			return agility;
		if (type == 1)
			return agilityMod;
		if (type == 2)
			return agilityPotential;
		if (type == 3)
			return agilityTendency;
		break;
	case 3:
		if (type == 0)
			return constitution;
		if (type == 1)
			return constitutionMod;
		if (type == 2)
			return constitutionPotential;
		if (type == 3)
			return constitutionTendency;
		break;
	case 4:
		if (type == 0)
			return intellect;
		if (type == 1)
			return intellectMod;
		if (type == 2)
			return intellectPotential;
		if (type == 3)
			return intellectTendency;
		break;
	case 5:
		if (type == 0)
			return willpower;
		if (type == 1)
			return willpowerMod;
		if (type == 2)
			return willpowerPotential;
		if (type == 3)
			return willpowerTendency;
		break;
	case 6:
		if (type == 0)
			return perception;
		if (type == 1)
			return perceptionMod;
		if (type == 2)
			return perceptionPotential;
		if (type == 3)
			return perceptionTendency;
		break;
	case 7:
		if (type == 0)
			return communication;
		if (type == 1)
			return communicationMod;
		if (type == 2)
			return communicationPotential;
		if (type == 3)
			return communicationTendency;
		break;
	case 8:
		if (type == 0)
			return beauty;
		if (type == 1)
			return beautyMod;
		if (type == 2)
			return beautyPotential;
		if (type == 3)
			return beautyTendency;
		break;
	default:
		break;
	}
	return 0;
}
std::string Character::getAge() { std::string r = "WOAH"; return r; }
float Character::getLowerHeight() { return lowerHeight; }
float Character::getUpperHeight() { return upperHeight; }
float Character::getBMILowStandard() { return bmiLowStandard; }
float Character::getBMIHighStandard() { return bmiHighStandard; }

int Character::getRestrictMax() { return restrictMax; }
int Character::getRestrictMaxMod() { return restrictMaxMod; }
int Character::getRestrict() { return restrict; }
int Character::getOverheatMax() { return overheatMax; }
int Character::getOverheatMaxMod() { return overheatMaxMod; }
int Character::getOverheat() { return overheat; }
int Character::getEquipLoadMax() { return equipLoadMax; }
int Character::getEquipLoadMod() { return equipLoadMaxMod; }
float Character::getEquipLoad() { return equipLoad; }
int Character::getLiftMax() { return 0; }
int Character::getSkillPoints() { return skillPoints; }
int Character::getSpeed() { return speed; }
int Character::getSpeedMod() { return speedMod; }
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
std::string Character::getEyesight() { return eyesight; }

float Character::getTraining(int stat, bool hours)
{
	switch (stat)
	{
	case 0:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursStrength.size(); i++)
				h += hoursStrength[i];
			return h;
		}
		return trainingStrength;
		break;
	case 1:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursDexterity.size(); i++)
				h += hoursDexterity[i];
			return h;
		}
		return trainingDexterity;
		break;
	case 2:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursAgility.size(); i++)
				h += hoursAgility[i];
			return h;
		}
		return trainingAgility;
		break;
	case 3:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursConstitution.size(); i++)
				h += hoursConstitution[i];
			return h;
		}
		return trainingConstitution;
		break;
	case 4:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursIntellect.size(); i++)
				h += hoursIntellect[i];
			return h;
		}
		return trainingIntellect;
		break;
	case 5:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursWillpower.size(); i++)
				h += hoursWillpower[i];
			return h;
		}
		return trainingWillpower;
		break;
	case 6:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursPerception.size(); i++)
				h += hoursPerception[i];
			return h;
		}
		return trainingPerception;
		break;
	case 7:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursCommunication.size(); i++)
				h += hoursCommunication[i];
			return h;
		}
		return trainingCommunication;
		break;
	case 8:
		if (hours)
		{
			float h = 0;
			for (int i = 0; i < hoursBeauty.size(); i++)
				h += hoursBeauty[i];
			return h;
		}
		return trainingBeauty;
		break;
	default:
		break;
	}
	return 0;
}