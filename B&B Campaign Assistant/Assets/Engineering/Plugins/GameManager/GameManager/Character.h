#include <iostream>
#include <stdlib.h>
#include "Entity.h"

#ifndef __CHARACTER_H_INCLUDED__
#define __CHARACTER_H_INCLUDED__

class Character : public Entity		//TODO	Implement effects of age, effects of agility/strength on height/weight, skills
{
public:
	//construction methods
	Character();				//generates a .txt file to store all character info
	~Character();
	
	//set methods
	void setStrength(int s);			//
	void setDexterity(int d);			//
	void setAgility(int a);				//
	void setConstitution(int c);		//
	void setIntellect(int i);			//
	void setWillpower(int w);			//
	void setPerception(int p);			//
	void setCharisma(int c);			//
	void setBeauty(int b);				//
	void setBirth(int y, int d, int s);	//earth years, days, and seconds since character birth upon character initialization
	void setBaseHeight(float h);
	void setBaseWeight(float w);
	
	//runtime methods
	bool buildCharacter();				//builds the character from all input information. if information needed is missing, returns false
	bool buildStrength();
	bool buildDexterity();
	bool buildAgility();
	bool buildConstitution();
	bool buildWillpower();
	bool buildPerception();
	
	//get methods
	char *getName();
	int getStrength();					//
	int getDexterity();					//
	int getAgility();					//
	int getConstitution();				//
	int getIntellect();					//
	int getWillpower();					//
	int getPerception();				//
	int getCharisma();					//
	int getBeauty();					//
	char *getAge();

	int getRestrictMax();
	int getRestrict();
	int getOverheatMax();
	int getOverheat();
	int getDamageBonus();
	int getCarryMax();
	float getCarry();
	int getLiftMax();
	int getWeaponProficiency();
	int getInitiativeBase();
	int getInitiative();
	int getDefenseBase();
	int getDefense();
	int getHealthMax();
	float getHealth();
	float getHealSpeed();
	float getBaseWeight();
	float getBaseHeight();
	float getWeight();
	float getHeight();
	int getResolve();
	int getSorceryBonus();
	int getEyeglassesBonus();
	char *getEyesight();
private:
	//base stats
	int strength;						//3d6 for humans
	int dexterity;						//3d6 for humans
	int agility;						//3d6 for humans
	int constitution;					//3d6 for humans
	int intellect;						//3d6 for humans
	int willpower;						//3d6 for humans
	int perception;						//3d6 for humans
	int charisma;						//3d6 for humans
	int beauty;							//3d6 for humans
	int years;							//number of earth years old
	int days;							//number of earth days since earth birthdate
	int seconds;						//number of earth seconds since earth 24-hour clock time of birth
	
	//dependant stats
	int restrictMax;					//
	int restrict;						//
	int overheatMax;					//
	int overheat;						//
	int damageBonus;					//damage bonus on strength weapons
	int carryMax;						//carry weight
	float carry;						//weight carried
	int liftMax;						//lift weight
	int weaponProficiency;				//the number of points a character gets to put toward broad weapon skill modifiers
	int initiativeBase;					//base initiative
	int initiative;						//total initiative
	int defenseBase;					//base defense
	int defense;						//total defense
	int healthMax;						//max health
	float health;						//health
	float healSpeed;					//speed of healing
	float baseWeight;					//weight as set by player and affected by strength
	float baseHeight;					//height as set by player and affected by agility
	float weight;						//weight with all factors
	float height;						//height with all factors
	int resolve;						//
	int sorceryBonus;					//
	int eyeglassesBonus;				//
	char *eyesight;						//

	//passive combat skills


	//active combat skills


	//reactive combat skills

	
	//dev variables
	std::string character_dot_txt;
};

#endif
