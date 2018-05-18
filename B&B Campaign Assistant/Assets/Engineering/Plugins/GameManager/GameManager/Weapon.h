#include <iostream>
#include <stdlib.h>
#include "Item.h"

#ifndef __WEAPON_H_INCLUDED__
#define __WEAPON_H_INCLUDED__

class Weapon : Item
{
public:
	Weapon();
	~Weapon();
	bool addForm(char *formData);
protected:
	//base information
	int forms;				//forms
	char **form;			//name of corresponding form
	int *hands;				//hands required to use corresponding form
	bool *cut;				//if the form can cut
	bool *crush;			//if the form can crush
	bool *stab;				//if the form can stab
	bool *ranged;			//if the form is ranged
	
	//generic upgradeable stats
	int *draw;				//the amount of time it takes to prepare the weapon for use in combat

	//melee effective upgradeable stats
	int *parry;				//the form's parrying capability (0 means it cannot effectively parry)
	int *feint;				//the form's feinting capability (0 means it cannot effectively feint)

	//ranged effective upgradeable stats
	int *aim;				//the form's aiming capability (0 means it cannot effectively be aimed)

	//melee weapon specific stats, not used if not melee
	int *cutDice;			//damage die count for a cut attack
	int *cutDamage;			//damage die type for a cut attack
	int *cutMod;			//damage modifier for a cut attack
	float *cutReach;		//the reach of a cut attack, crush attacks suffer more penalties if the opponent is farther within or out of reach
	float *cutArc;			//the area of the cut's arc, if this is not fully available, the attack will suffer penalties
	float *cutHeight;		//the height that must be available for the cut, if it is not available, the attack will suffer penalties
	float *cutTime;			//the time it takes to make a cut attack
	int *cutCutting;		//the actual cutting value of the cut
	int *cutCrusing;		//the crushing value of the cut
	int *cutStabbing;		//the stabbing value of the cut

	int *crushDice;			//damage die count for a crush attack
	int *crushDamage;		//damage die type for a crush attack
	int *crushMod;			//damage modifier for a crush attack
	float *crushReach;		//the reach of a crush attack, crush attacks suffer more penalties if the opponent is farther within or out of reach
	float *crushArc;		//the area of the crush's arc, if this is not fully available, the attack will suffer penalties
	float *crushHeight;		//the height that must be available for the crush, if it is not available, the attack will suffer penalties
	float *crushTime;		//the time it takes to make a crush attack
	int *crushCutting;		//the actual cutting value of the crush
	int *crushCrusing;		//the crushing value of the crush
	int *crushStabbing;		//the stabbing value of the crush

	int *stabDice;			//damage die count for a stab attack
	int *stabDamage;		//damage die type for a stab attack
	int *stabMod;			//damage modifier for a stab attack
	float *stabReach;		//the reach of a stab attack, stab attacks massively penalized if opponent is within the weapon length or outside of reach
	float *stabArc;			//the area of the stab's arc, if this is not fully available, the attack will suffer penalties
	float *stabHeight;		//the height that must be available for the stab, if it is not available, the attack will suffer penalties
	float *stabTime;		//the time it takes to make a stab attack
	int *stabCutting;		//the actual cutting value of the stab
	int *stabCrusing;		//the crushing value of the stab
	int *stabStabbing;		//the stabbing value of the stab

	//ranged weapon specific stats, not used if not ranged
	//THESE STATS WILL NEED TO BE COMPLETELY REWORKED, THEY NEED TO USE A FAIRLY MORE COMPLEX SYSTEM
	int *poundage;			//the poundage that can be fired with, affected by strength and training
	float *reloadTime;		//the time it takes to prepare a round for firing
	float *fireTime;		//the time it takes to fire a round
	int *projectiles;		//the number of projectiles fired at one time
	//note that all attacks made with a ranged weapon are crush and stab

	//INFO ON COMBAT:
	/*
	COMBAT IS TAKEN IN STEPS LASTING 1(?)SECOND EACH
	EACH STEP, EVERYONE IS ABLE TO DO SOMETHING
	IN REALITY, THE DECISIONS BEING MADE AT EACH STEP MAY BE OFFSET BY A SMALL AMOUNT OF TIME
	EVERY ACTION HAS AN AMOUNT OF TIME IN SECONDS IT WILL TAKE
	EVERY ACTION HAS A POINT DURING THAT TIME AFTER WHICH THE ACTION WILL HAVE ITS DESIRED EFFECT
	THIS MEANS THAT A SWORD SWING MAY TAKE .6 SECONDS, BUT IT COULD HIT IN THE FIRST .3 SECONDS
	THE TIME AN ACTION TAKES CAN BE DEPENDANT UPON THE LAST TAKEN ACTION
	WAIT: WAIT FOR 1 SECOND OR A CHOSEN OPPONENTS NEXT ACTION
	ATTACK: ATTACK A CHOSEN OPPONENT FOR X SECONDS
	PARRY: SPEND X SECONDS PARRYING
	FEINT: SPEND X SECONDS FEINTING
	MOVE: MOVE A SET DISTANCE FOR THE AMOUNT OF TIME 
	DODGE: DODGE AWAY FROM A CHOSEN OPPONENT, LEAVES YOU VULNERABLE TO OTHER OPPONENTS
	GRAPPLE: AGH THIS ONE SUCKS

	YOU CAN DO ANY ACTION WHILE MOVING IN COMBAT, BUT YOU WILL HAVE A LONGER ACTION TIME AND A PENALTY
	*/

	//INFO ON CRITICAL HITS:
	//A CRITICAL HIT DOUBLES DICE
	//ROLLING A CRITICAL ALLOWS THE PLAYER TO ROLL ON THE CRITICAL TABLE FOR THAT SPECIFIC CHARACTER/MONSTER
	//THE CRITICAL TABLE RESULTS ARE DIRECTLY AFFECTED BY ARMOR WORN, HEALTH CONDITIONS, WEAPON/FORM BEING USED, AND ANY OTHER APPLICABLE FACTORS
	//SO IF WEARING A HELMET, DYING OF BEING HIT IN THE HEAD BY A SWORD IS INCREDIBLY UNLIKELY
	//WHILE IF WEARING A GAMBESON, BEING STABBED IN THE HEART OR LUNG AND DYING SHORTLY AFTER IS A STRONG POSSIBILITY

	//INFO ON DAMAGE AND BLEEDING:
	//A CRUSH ATTACK WILL RESULT IN 0 LEVELS OF BLEEDING
	//A STAB ATTACK WILL RESULT IN 1 LEVELS OF BLEEDING
	//A CUT ATTACK WILL RESULT IN 2 LEVELS OF BLEEDING
	//THE HIGHEST BLEEDING RESULT WILL BE TAKEN FOR MULTI-TYPE ATTACKS
	//TAKING 6 DAMAGE OR MORE FROM AN ATTACK INFLICTS A LEVEL OF BLEEDING
	//ALL BLEEDING FROM CRUSH ATTACKS IS INTERNAL
	//BLEEDING HAS A CHANCE TO STOP ON ITS OWN. THIS CHANCE REDUCES WITH EACH LEVEL OF BLEEDING. AT 5 LEVELS OF BLEEDING, YOU'RE FUCKED WITHOUT TREATMENT
	//A LEVEL OF BLEEDING MEANS A LOSS OF 1 HEALTH PER 10 MINUTES
	//SO, 13 LEVELS OF BLEEDING MEANS A LOSS OF 1.3 HEALTH PER MINUTE
	//A STAB TO THE HEART CAN RANGE FROM 100 to 500 LEVELS OF BLEEDING
	//USUALLY, AFTER A FIGHT, YOU WILL NEED TO SEE A HEALER IF ANYONE GOT INJURED SIGNIFICANTLY
	//HEALERS CAN BE UNRELIABLE
	//HEALING MAGIC NEVER WORKS GOOD
	//ONE OF THE HEALING SPELLS JUST FORCES THE BLOOD TO CLOT IN THE AREA OF BLEEDING. THIS SOMETIMES LATER RESULTS IN AMPUTATION BUT IS QUICK AND EASY TO CAST
	//ONE OF THE OTHER HEALING SPELLS IS MORE OBVIOUSLY BLOOD MAGIC AND THEREFORE SCARY, BUT IS BASICALLY A BLOOD TRANSFUSION. KEEPS SOMEONE ALIVE FOR A BIT LONGER ASSUMING THEIR BODY DOESN'T REJECT THE TRANSFUSION
	//ONE HEALING GOO CAN BE FORCED INTO WOUNDS TO CLOSE THEM, ITS STERILE SO DON'T WORRY ABOUT IT, THOUGH IT MIGHT PERMANENTLY LOWER YOUR HEALTH
	//ONE HEALING DRINK BASICALLY IS JUST SUBSTITUTE BLOOD STUFF, BUT IT ONLY STAYS IN YOUR SYSTEM FOR A FEW DAYS SO ITS A TEMP HEALTH BOOSTER FOR BLEEDING RECOVERY
	//ONE HEALING GOO STERILIZES WOUNDS AND THATS IT, WOW
};

#endif
