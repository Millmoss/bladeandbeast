#include <iostream>
#include <stdlib.h>
#include "Weapon.h"

#ifndef __SWORD_H_INCLUDED__
#define __SWORD_H_INCLUDED__

class Sword : Weapon				//note, portions of this code are experimental
{
public:
	Sword(char *line);
	//void addForm(char *line);
	//void setDescription(char *line);
	//~Sword();
protected:
	//base information
	float totalLength;				//note, this length is from blade tip to pommel
	float hiltLength;
	float bladeLength;				//note, this is the length from hilt end to blade tip
	
	//hilt information
	char *crossguardType;
	char *basketType;				//complex, simple, half-basket, full-basket, none
	bool nagel;
	char *ringGuardType;			//two shield, one shield, two empty, one empty, none
	bool fingerGuard;
	
	//blade information
	char *frontShape;				//blade shape in front
	char *backShape;				//blade shape in back
	float pommel;					//pommel type
	float bladeSharp;				//number from 0 to 1 representing blade sharpness. 1 is maximum sharpness, 0 is completely dull
	float bladePoint;				//number from 0 to 1 representing the piercing capability of the blade. same as sharp
	
};

#endif
