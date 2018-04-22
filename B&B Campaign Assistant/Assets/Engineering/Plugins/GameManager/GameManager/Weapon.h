#include <iostream>
#include <stdlib.h>
#include "Item.h"

#ifndef __WEAPON_H_INCLUDED__
#define __WEAPON_H_INCLUDED__

class Weapon : Item
{
public:
	Weapon();
protected:
	//base information
	char *type;				//type of weapon: pole, sword, dagger, hammer/axe
	int forms;				//forms
	char **form;			//name of corresponding form
	int *hands;				//hands required to use corresponding form
	int *dice;				//number of damage die of corresponding form
	int *damage;			//damage die of corresponding form
	float *reach;			//reach of corresponding form
	int *coverage;			//a number representing the area that an attack from this weapon covers, directly affects dodge attempts

	//upgradeable stats
	int *speed;				//speed of corresponding form
	int *draw;				//draw speed of corresponding form
	int *attack;			//
	int *defend;			//
	int *parry;				//
	int *feint;				//
	int *retreat;			//
	int *grapple;			//corresponding form number will be NULL if no grapple
};

#endif
