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
	Character();						//generates a .txt file to store all character info
	~Character();
	
	//set methods
	void setStrength(int s);			//
	void setDexterity(int d);			//
	void setAgility(int a);				//
	void setConstitution(int c);		//
	void setIntellect(int i);			//
	void setWillpower(int w);			//
	void setPerception(int p);			//
	void setCommunication(int c);		//
	void setBeauty(int b);				//
	void setYears(int y);				//
	void setDays(int d);				//
	void setSeconds(int s);				//
	void setHeight(float h);			//
	void setWeight(float w);			//
	
	//runtime methods
	bool buildCharacter();				//builds the character from all input information. if information needed is missing, returns false
	
	//get methods
	std::string getName();
	int getStrength();					//
	int getDexterity();					//
	int getAgility();					//
	int getConstitution();				//
	int getIntellect();					//
	int getWillpower();					//
	int getPerception();				//
	int getCommunication();				//
	int getBeauty();					//
	std::string getAge();

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
	std::string getEyesight();
private:
	//base stats

	//all base stats are generated using an unmodified 3d6 roll
	//whether they can be switched around is GM choice
	//to increase or decrease stats, use stat points
	//a decrease will always yield 1 stat point
	//an increase costs one stat point up to the stat being 11
	//from that point, an increase costs 2 for 12, 3 for 13, 4 for 14, and so on until it is 8 for 18
	//stats are bounded between 3 and their potential multiplied by 18 rounded down at character creation
	//stat point amount is determined by a roll of 6d6

	int strength;						//
	int strengthMod;					//can be naturally modified by height/weight
	int dexterity;						//
	int dexterityMod;					//
	int agility;						//
	int agilityMod;						//
	int constitution;					//
	int constitutionMod;				//can be naturally modified by height/weight
	int intellect;						//
	int intellectMod;					//
	int willpower;						//
	int willpowerMod;					//
	int perception;						//
	int perceptionMod;					//
	int communication;					//
	int communicationMod;				//
	int beauty;							//
	int beautyMod;						//

	int years;							//age in earth years rounded down
	int days;							//age in earth days rounded down
	int seconds;						//age in earth seconds rounded down
	float height;						//height as set by player
	float heightMod;					//mod on height
	float weight;						//weight as set by player
	float weightMod;					//mod on weight

	//character creation stats

	int statPoints;						//stat points are used to modify character stats after they are rolled. set at a roll of 6d6
	int proficiencyPoints;				//proficiency points are used to allocate proficiencies at the start of the game

	//race information

	//potential is a percentage multiplier regularly between 0 and 1.25
	//this modifier is directly applied to its stat after it is rolled initialy
	//these modifiers DO NOT affect stat point allocation in any way

	//tendency is a number usually between -2 and 2
	//at 0, tendency does nothing
	//at 1, tendency adds 1 extra 1d6 roll to that stat's roll and drops the lowest 1d6 roll
	//at 2, tendency adds 2 extra 1d6 rolls and drops the lowest 2 1d6 rolls
	//at -1, tendency adds 1 extra 1d6 roll and drops the highest 1d6 roll
	//at -2, tendency adds 2 extra 1d6 rolls and drops the highest 2 1d6 rolls

	float strengthPotential;			//
	int strengthTendency;				//elven tendency -1
	float dexterityPotential;			//
	int dexterityTendency;				//elven tendency 2
	float agilityPotential;				//
	int agilityTendency;				//elven tendency 1
	float constitutionPotential;		//
	int constitutionTendency;			//elven tendency -2
	float intellectPotential;			//
	int intellectTendency;				//
	float willpowerPotential;			//
	int willpowerTendency;				//
	float perceptionPotential;			//
	int perceptionTendency;				//elven tendency 2
	float communicationPotential;		//
	int communicationTendency;			//elven tendency -1
	float beautyPotential;				//
	int beautyTendency;					//elven tendency 1
	float statPointsBonus;				//bonus of stat points, for example humans have this number set at 6, while elves have it at -12
	
	//general dependant stats

	int restrictMax;					//
	int restrictMaxMod;					//
	int restrict;						//

	int overheatMax;					//
	int overheatMaxMod;					//
	int overheat;						//

	int carryMax;						//carryable weight
	int carryMaxMod;					//mod on carryable weight
	float carry;						//weight carried

	bool buildCarry();					//carry setup

	int liftMax;						//lift weight
	int liftMaxMod;						//mod on lift weight

	int speed;							//base speed
	int speedMod;						//mod on speed

	int healthMax;						//max health
	int healthMaxMod;					//mod on max health

	int dodge;							//base dodge capability
	int dodgeMod;						//mod on dodge capability

	float health;						//health
	float healthMod;					//mod on health, ignores healthMax
	float healRate;						//speed of healing
	float healRateMod;					//mod on speed of healing

	int resolve;						//
	int resolveMod;						//mod on resolve
	int sorceryBonus;					//
	int sorceryBonusMod;				//
	bool buildSorcery();				//sorceryBonus setup
	int eyeglassesBonus;				//
	int eyeglassesBonusMod;				//
	std::string eyesight;				//

	bool buildEyesight();				//eyesight setup
	bool buildAgilityStats();			//builds jump, speed, move, and dodge
	bool buildHeightMod();				//recompute height mod
	bool buildWeightMod();				//recompute weight mod
	bool buildProficiency();			//give starting proficiency points
	bool buildLift();					//lift setup

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

	//training stats

	//training allows for an increase in the effective stat
	//training also goes down over time if the stat is not being trained
	//training is gained naturally from daily activities
	//character's are allowed to start with training in stats of their choice
	//stats train at a rate 2^n, n being an integer representing the stat bonus
	//the points per month of training are given the square root of the base stat
	//a month of training counts as 30 training hours in a month, as long as this minimum is being met the training points will increase
	//training hours are not always an hour, a high intensity work out for 30 minutes yields a training hour, and so does four hours of travel
	//the month of training hour count goes up by the rate as that increases (30, 32, 36, 44, 60, 92, 156)
	//if a character is incapable of meeting the old training hour requirement, their training will go down by the amount they missed it by
	//the training is recalculated at the end of every day
	//if (hours / (30 + 2^0 ~ 2^(n-1)) - 1 < 0)
	//	training += (30 + 2^0 ~ 2^n - 1) - 1
	//training is capped on a minimum day basis at double the training hour requirement
	//this means that if you exceed the training hour requirement in ratio form, then further training will have no yields
	//so if in a day you trained 3 hours, but your requirement was 30 hours per month, then you would only receive two hours of training

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
	float trainingPerception;			//trained through sensory deprivation training, so basically perception must usually be specifically trained
	float trainingPerceptionMin;		//a training minimum equal to a quarter of the max achieved perception training
	std::stack<float> hoursPerception;
	float trainingCommunication;		//trained through social interaction, reading, etc
	float trainingCommunicationMin;		//a training minimum equal to half of the max achieved communication training
	std::stack<float> hoursCommunication;
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
