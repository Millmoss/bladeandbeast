#include <iostream>
#include <stdlib.h>
#include <stack>
#include "Being.h"
#include "Weapon.h"
#include "Armor.h"

#ifndef __CHARACTER_H_INCLUDED__
#define __CHARACTER_H_INCLUDED__

class Character : public Being		//TODO	Implement effects of age, effects of agility/strength on height/weight, skills
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
	void setYears(int y);				//birth info
	void setDays(int d);
	void setSeconds(int s);
	void setHeight(float h);
	void setWeight(float w);
	
	//runtime methods
	bool buildCharacter();				//builds the character from all input information. if information needed is missing, returns false
	
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
	int getRestrictMaxMod();
	int getRestrict();
	int getOverheatMax();
	int getOverheatMaxMod();
	int getOverheat();
	int getCarryMax();
	int getCarryMaxMod();
	float getCarry();
	int getLiftMax();
	int getLiftMaxMod();
	int getProficiencyPoints();
	int getSpeed();
	int getSpeedMod();
	int getDodge();
	int getDodgeMod();
	int getHealthMax();
	int getHealthMaxMod();
	float getHealth();
	float getHealthMod();
	float getHealRate();
	float getHealRateMod();
	float getHeight();
	float getHeightMod();
	float getWeight();
	float getWeightMod();
	int getResolve();
	int getResolveMod();
	int getSorceryBonus();
	int getSorceryBonusMod();
	int getEyeglassesBonus();
	int getEyeglassesBonusMod();
	char *getEyesight();
private:
	//base stats
	int strength;						//3d6 for humans
	int strengthMod;					//
	int dexterity;						//3d6 for humans
	int dexterityMod;					//
	int agility;						//3d6 for humans
	int agilityMod;						//
	int constitution;					//3d6 for humans
	int constitutionMod;				//
	int intellect;						//3d6 for humans
	int intellectMod;					//
	int willpower;						//3d6 for humans
	int willpowerMod;					//
	int perception;						//3d6 for humans
	int perceptionMod;					//
	int charisma;						//3d6 for humans
	int charismaMod;					//
	int beauty;							//3d6 for humans
	int beautyMod;						//
	int years;							//number of earth years old
	int days;							//number of earth days since earth birthdate
	int seconds;						//number of earth seconds since earth 24-hour clock time of birth
	
	//general dependant stats
	int restrictMax;				//
	int restrictMaxMod;					//
	int restrict;						//

	int overheatMax;				//
	int overheatMaxMod;					//
	int overheat;						//

	int carryMax;					//carryable weight
	int carryMaxMod;					//mod on carryable weight
	float carry;						//weight carried

	int liftMax;					//lift weight
	int liftMaxMod;						//mod on lift weight

	bool buildCarry();					//carry and lift setup

	int proficiencyPoints;				//proficiency points are used to allocate proficiencies at the start of the game
	bool buildProficiency();			//give starting proficiency points

	int speed;						//base speed
	int speedMod;						//mod on speed

	int healthMax;					//max health
	int healthMaxMod;					//mod on max health

	int dodge;						//base dodge capability
	int dodgeMod;						//mod on dodge capability

	float health;						//health
	float healthMod;					//mod on health, ignores healthMax
	float healRate;					//speed of healing
	float healRateMod;					//mod on speed of healing

	float height;					//height as set by player
	float heightMod;					//mod on height
	bool buildHeightMod();				//recompute height mod
	float weight;					//weight as set by player
	float weightMod;					//mod on weight
	bool buildWeightMod();				//recompute weight mod

	int resolve;						//
	int resolveMod;						//mod on resolve
	int sorceryBonus;					//
	int sorceryBonusMod;				//
	bool buildSorcery();				//sorceryBonus setup
	int eyeglassesBonus;				//
	int eyeglassesBonusMod;				//
	char *eyesight;						//
	bool buildEyesight();				//eyesight setup

	bool buildAgilityStats();			//builds jump, speed, move, and dodge

	//defense stats
	//these stats all represent the base defense a person's body provides against attacks
	//the defense number is between 0 and 20, being 0% to 100% defense
	//defense contains keys listing every body part's defense against a certain damage type
	//these damage types can technically be anything, but in the case of this ruleset:
	//0 is cut damage, 1 is crush damage, and 2 is stab damage
	//other damage types can be added, but input files will have to be edited to account for that damage type
	std::unordered_map<std::string, int *> defense;
	std::unordered_map<std::string, Armor *> armors;

	//passive basic combat skills
	int awareness;	//awareness of battle environment. Reduced weather penalties, allows for waiting on multiple opponents at higher levels
	int reaction;	//affects the reaction time of the character in combat

	//active basic combat skills
	int move;
	int dodge;		//can do all actions while dodging, but the actions will be far less effective and this slightly reduces dodge chance
	int cut;		//when making an attack, you click attack, then select the body part(s) to aim for.
	int crush;		//the more body parts you select to aim for, the higher a hit rate your character will have.
	int stab;		//however, high hit rate is useless if the defense of where the weapon hits is too high
	int parry;
	int feint;		//effectiveness on chosen character goes down after each use
	int grapple;
	int aim;		//the character's ability to aim with ranged weapons

	//passive basic adventure skills
	//training allows for an increase in the effective stat
	//training also goes down over time if the stat is not being trained
	//training is gained naturally from daily activities
	//character's are allowed to start with training in stats of their choice
	//stats train at a rate 2^n, n being an integer representing the stat bonus
	//the points per month of training are given the square root of the base stat
	//a month of training counts as 30 training hours in a month, as long as this minimum is being met the training points will increase
	//training hours are not always an hour, a high intensity work out for 30 minutes yields a training hour, and so does four hours of travel
	//the month of training hour count goes up by the rate as that increases (30, 32, 36, 44, 60, 92)
	//if a character is incapable of meeting the old training hour requirement, their training will go down by the amount they missed it by
	//the training is recalculated at the end of every day
	//if (hours / (30 + 2^0 ~ 2^(n-1)) - 1 < 0)
	//	training += (30 + 2^0 ~ 2^n - 1) - 1
	float trainingStrength;				//trained through combat, travel, lifting, etc
	std::stack<float> hoursStrength;	//hours of training over the past month
	float trainingDexterity;			//trained through combat, crafting, cooking, etc
	std::stack<float> hoursDexterity;
	float trainingAgility;				//trained through combat, sprinting, etc
	std::stack<float> hoursAgility;
	float trainingConstitution;			//trained through travel, eating, etc
	std::stack<float> hoursConstitution;
	float trainingIntellect;			//trained through reading, travel, etc
	float trainingIntellectMin;			//a training minimum equal to two-thirds of the max achieved intellect training
	std::stack<float> hoursIntellect;
	float trainingWillpower;			//trained through meditation and ???
	float trainingWillpowerMin;			//a training minimum equal to half of the max achieved willpower training
	std::stack<float> hoursWillpower;
	float trainingPerception;			//trained through ???
	float trainingPerceptionMin;		//a training minimum equal to a quarter of the max achieved perception training
	std::stack<float> hoursPerception;
	float trainingCharisma;				//trained through social interaction, reading, etc
	float trainingCharismaMin;			//a training minimum equal to half of the max achieved charisma training
	std::stack<float> hoursCharisma;
	float trainingBeauty;				//trained through looking in a mirror and worrying about your looks
	float trainingBeautyMin;			//a training minimum equal to half of the max achieved beauty training
	std::stack<float> hoursBeauty;

	//IMPLEMENT SKILL TREES FOR COMBAT AND ADVENTURE SKILLS

	//CHARACTERS CAN CHOOSE WHAT TO LEARN EVERY NIGHT OR MORNING, THIS IS FOR TRAINING SKILLS
	//SKILLS INCREASE AT THE SAME RATE WITH TRAINING
	//SKILLS INCREASE FASTER WITH ACTUAL USE OF THEM, BUT THIS CAN OFTEN COME AT GREAT RISK
	//COMBAT INCREASES COMBAT SKILLS FASTER THAN TRAINING, BUT IS OF COURSE VERY DANGEROUS
	//COMBAT EXPERIENCE IS NOT GAINED IF A BATTLE IS EASILY WON, THERE MUST BE A SIGNIFICANT CHANCE OF FAILURE AND A SMALL CHANCE OF DEATH

	//dev variables
	std::string character_dot_txt;
};

#endif
