#include <iostream>
#include <stdlib.h>
#include <deque>
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
	void setHeight(float h);			//we assume that height limits have been set in UI code
	void setWeight(float w);			//we assume that bmi calculation has been done in UI code
	
	//runtime methods
	bool buildCharacter();				//builds the character from all input information. if information needed is missing, returns false
	
	//get methods
	std::string getName();
	float getStat(int stat, int type);	//get stat and type of stat (0 for stat, 1 for statMod, 2 for statPotential, 3 for statTendency)
	std::string getAge();
	float getLowerHeight();
	float getUpperHeight();
	float getBMILowStandard();
	float getBMIHighStandard();

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
	int getSkillPoints();
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
	float getTraining(int stat, bool hours);
private:
	//base stats

	//all base stats are generated using an unmodified 3d6 roll
	//whether they can be switched around is GM choice
	//to increase or decrease stats, use stat points
	//a decrease will always yield 1 stat point
	//an increase costs one stat point up to the stat being 11
	//from that point, an increase costs 2 for 12, 3 for 13, 4 for 14, and so on until it is 8 for 18
	//stats are bounded between 3 and their potential multiplied by 18 rounded down at character creation
	//stat point amount is determined by a roll of 5d6

	int strength;						//strength affects lift amount, carry amount, crush damage, and to an extent modifies character weight
	int strengthMod;					//
	int dexterity;						//dexterity affects the character's capability for fine motor skills
	int dexterityMod;					//
	int agility;						//agility affects a character's speed in performing physical actions
	int agilityMod;						//
	int constitution;					//constitution affects the body's capability to deal with wounds, physical strain, and disease
	int constitutionMod;				//
	int intellect;						//intellect affects the mind's capability to solve problems and process complex information
	int intellectMod;					//
	int willpower;						//willpower affects the mind's capability to deal with pain, and mental strain. Affects memory. Affects magic inclination
	int willpowerMod;					//
	int perception;						//perception affects a character's capability to notice things as well as a character's eyesight
	int perceptionMod;					//
	int communication;					//communication affects a character's capability to communicate with others through speech and expression as well as understand others
	int communicationMod;				//
	int beauty;							//beauty affects a character's physical appearance, voice, and natural charisma
	int beautyMod;						//

	int years;							//age in earth years rounded down
	int days;							//age in earth days rounded down
	int seconds;						//age in earth seconds rounded down
	float height;						//height as set by player in inches, should use a slider limited by upperHeight and lowerHeight
	float heightMod;					//mod on height, affected by probably nothing but I'm gonna leave this here anyway just in case
	float weight;						//weight as set by player in pounds, should use a slider that is affected by height, this can go up or down depending on eating, exercise, illness, etc
	float weightMod;					//mod on weight, affected by strength in tandem with height, and things being worn/carried

	//character creation stats

	int statPoints;						//stat points are used to modify character stats after they are rolled. set at a roll of 5d6
	int skillPoints;					//skill points are used to allocate proficiencies at the start of the game

	//race information

	//these races are not balanced, nor should they be
	//different players will regularly gravitate toward different races due to preference between advantages and disadvantages

	//potential is a percentage multiplier regularly between 0 and 1.25
	//this modifier is directly applied to its stat after it is rolled initialy
	//these modifiers DO NOT affect stat point allocation in any way

	//tendency is a number usually between -3 and 3
	//at 0, tendency does nothing
	//at 1, tendency adds 1 extra 1d6 roll to that stat's roll and drops the lowest 1d6 roll
	//at 2, tendency adds 2 extra 1d6 rolls and drops the lowest 2 1d6 rolls
	//at -1, tendency adds 1 extra 1d6 roll and drops the highest 1d6 roll
	//at -2, tendency adds 2 extra 1d6 rolls and drops the highest 2 1d6 rolls
	//and so on

	float strengthPotential;			//
	int strengthTendency;				//elven tendency -1, kobold tendency -2, demon tendency 1
	float dexterityPotential;			//
	int dexterityTendency;				//elven tendency 2, kobold tendency 2, demon tendency 1
	float agilityPotential;				//
	int agilityTendency;				//elven tendency 1, kobold tendency 2
	float constitutionPotential;		//
	int constitutionTendency;			//elven tendency -2, kobold tendency -3, demon tendency 2
	float intellectPotential;			//
	int intellectTendency;				//kobold tendency -1
	float willpowerPotential;			//
	int willpowerTendency;				//demon tendency 1
	float perceptionPotential;			//
	int perceptionTendency;				//elven tendency 2, kobold tendency 1
	float communicationPotential;		//
	int communicationTendency;			//elven tendency -1, kobold tendency -2
	float beautyPotential;				//
	int beautyTendency;					//elven tendency 1
	float statPointsBonus;				//bonus of stat points, 10 for humans, -5 for elves, 0 for kobolds, 0 for delphi, -5 for demons

	float lowerHeight;					//minimum standard height
	float upperHeight;					//maximum standard height
	float bmiLowStandard;				//the standard bmi low for this race, 18.5 for humans, 17 for elves, 15 for kobolds, 18 for delphi, 21 for demons
	float bmiHighStandard;				//the standard bmi high for this race, 25 for humans, 23 for elves, 20 for kobolds, 24 for delphi, 28 for demons
	
	//race descriptions

	//humans : it's a human I mean come on

	//elves : are terrible and should not be allowed to be in this ruleset

	//kobolds : Kobolds are smaller folk with skin not quite scaly but not quite mammalian either. They tend to be less intelligent than other races, leading to kobold societies often being
	//a degree less civilized than human, elven, and delphien societies. As well, kobolds have a tendency to shun other races due to this difference. Cut off from magical capabilities, kobolds
	//are often martial experts by necessity.

	//delphi : Delphi are a strange combination of human and sea mammal. They match up with humans in many ways, but are capable of swimming extremely quickly and can hold their breath for up
	//to 10 minutes in some cases. However, delphi need more water than humans while on land, though they are better at filtering water than humans so have a wider selection of water to drink
	//which includes sea water.

	//demons : basically just people with horns because it's what's cool

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
	bool buildSkill();					//give starting skill points
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

	//skills

	//create a generic class for all skills
	
	//factors for adventure skill rolls
	//skill affects time it takes to make an action using that skill
	//skill affects the capability to perform difficult actions using that skill
	//skill affects the success of actions using that skill in a non-binary way
		//a medium roll results in medium success, a high-ish roll results in high-ish success
	
	//skills go up only through training them
	//you can technically just sit around and learn skills for a few years before doing anything in game, but money needs and campaign dangers will usually prevent this from happening
	//skills go down without use, but the amount they go down more slowly with more time

	//create skill groups: crafting, engineering, language, knowledge, combat, survival, agriculture, criminal, athletic, artistic, gathering, travel, magic, social, mathematics, and science
	//skill trees for more complex skills such as crafting, engineering, knowledge, magic, mathematics, and science
	//skill access/progression is only limited by the knowledge in the world and character capability, so a dark age campaign setting would make it difficult to learn higher maths and sciences

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
	std::deque<float> hoursStrength;	//hours of training over the past month
	float trainingDexterity;			//trained through combat, crafting, cooking, etc
	std::deque<float> hoursDexterity;
	float trainingAgility;				//trained through combat, sprinting, etc
	std::deque<float> hoursAgility;
	float trainingConstitution;			//trained through travel, eating, sleeping, etc
	std::deque<float> hoursConstitution;
	float trainingIntellect;			//trained through reading, travel, etc
	float trainingIntellectMin;			//a training minimum equal to two-thirds of the max achieved intellect training
	std::deque<float> hoursIntellect;
	float trainingWillpower;			//trained through meditation, memorization, and spell casting
	float trainingWillpowerMin;			//a training minimum equal to half of the max achieved willpower training
	std::deque<float> hoursWillpower;
	float trainingPerception;			//trained through sensory deprivation training, so basically perception must usually be specifically trained
	float trainingPerceptionMin;		//a training minimum equal to a quarter of the max achieved perception training
	std::deque<float> hoursPerception;
	float trainingCommunication;		//trained through social interaction, reading, etc
	float trainingCommunicationMin;		//a training minimum equal to half of the max achieved communication training
	std::deque<float> hoursCommunication;
	float trainingBeauty;				//trained through looking in a mirror and worrying about your looks
	float trainingBeautyMin;			//a training minimum equal to half of the max achieved beauty training
	std::deque<float> hoursBeauty;

	//CHARACTERS CAN CHOOSE WHAT TO LEARN EVERY NIGHT OR MORNING, THIS IS FOR TRAINING SKILLS
	//SKILLS INCREASE AT THE SAME RATE WITH TRAINING
	//SKILLS INCREASE FASTER WITH ACTUAL USE OF THEM, BUT THIS CAN OFTEN COME AT GREAT RISK
	//COMBAT INCREASES COMBAT SKILLS FASTER THAN TRAINING, BUT IS OF COURSE VERY DANGEROUS
	//COMBAT EXPERIENCE IS NOT GAINED IF A BATTLE IS EASILY WON, THERE MUST BE A SIGNIFICANT CHANCE OF FAILURE AND A SMALL CHANCE OF DEATH

	//dev variables

	std::string character_dot_txt;
};

#endif
