#include <iostream>
#include <stdlib.h>
#include "Entity.h"
#include "Weapon.h"

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
	int getDodgeBase();
	int getDodge();
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
	
	//general dependant stats
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
	int healthMax;						//max health
	int dodgeBase;						//the base dodge capability of the character
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

	//defense stats
	//these stats all represent the base defense a person's body provides against attacks
	//the defense number is between 0 and 20, being 0% to 100% defense
	int headDefenseBase;
	int neckDefenseBase;
	int chestDefenseBase;
	int stomachDefenseBase;
	int backDefenseBase;
	int shoulderRightDefenseBase;
	int shoulderLeftDefenseBase;
	int upperarmRightDefenseBase;
	int upperarmLeftDefenseBase;
	int forearmRightDefenseBase;
	int forearmLeftDefenseBase;
	int handRightDefenseBase;
	int handLeftDefenseBase;
	int crotchDefenseBase;
	int buttDefenseBase;
	int thighRightDefenseBase;
	int thighLeftDefenseBase;
	int shinRightDefenseBase;
	int shinLeftDefenseBase;
	int calfRightDefenseBase;
	int calfLeftDefenseBase;
	int footRightDefenseBase;
	int footLeftDefenseBase;
	int heelRightDefenseBase;
	int heelLeftDefenseBase;

	//passive basic combat skills
	int awareness;	//awareness of battle environment. Reduced weather penalties, allows for waiting on multiple opponents at higher levels
	int reaction;	//affects the reaction time of the character in combat

	//active basic combat skills
	int move;
	int dodge;		//can do all actions while dodging, but the actions will be far less effective and this slightly reduces dodge chance
	int cut;		//when making an attack, you click attack, then select the body part(s) to aim for.
	int crush;		//the more body parts you select to aim for, the higher a hit rate your character will have.
	int stab;		//however, high hit rate is useless if coverage is too high.
	int parry;
	int feint;		//effectiveness on chosen character goes down after each use
	int grapple;
	int aim;		//the character's ability to aim with ranged weapons

	//passive basic adventure skills
	//training allows for an increase in the effective stat
	//stats train very slowly
	//more time is required to train the stat at each training level
	//training also goes down over time if the stat is not being trained
	//training is gained naturally from daily activities
	//character's are allowed to start with training in stats of their choice
	float trainingStrength;				//trained through combat, travel, lifting, etc
	float trainingDexterity;			//trained through combat, crafting, cooking, etc
	float trainingAgility;				//trained through combat, sprinting, etc
	float trainingConstitution;			//trained through travel, eating, etc
	float trainingIntellect;			//trained through reading, travel, etc
	float trainingWillpower;			//trained through ???
	float trainingPerception;			//trained through ???
	float trainingCharisma;				//trained through social interaction, reading, etc
	float trainingBeauty;				//can you train this??? kinda maybe?

	//IMPLEMENT SKILL TREES FOR COMBAT AND ADVENTURE SKILLS

	//CHARACTERS CAN CHOOSE WHAT TO LEARN EVERY NIGHT OR MORNING, THIS CAN BE TRAINING COMBAT SKILLS OR NON-COMBAT SKILLS
	//COMBAT SKILLS AND NON-COMBAT SKILLS INCREASE AT THE SAME RATE WITH TRAINING
	//COMBAT INCREASES COMBAT SKILLS FASTER THAN TRAINING, BUT IS OF COURSE VERY DANGEROUS
	//COMBAT EXPERIENCE IS NOT GAINED IF A BATTLE IS EASILY WON, THERE MUST BE A SIGNIFICANT CHANCE OF FAILURE AND A SMALL CHANCE OF DEATH

	//dev variables
	std::string character_dot_txt;
};

#endif
