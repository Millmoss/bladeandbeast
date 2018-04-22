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
	float crossguardLength;
	float crossguardStrength;
	char *basketType;				//complex, simple, half-basket, full-basket, none
	float basketStrength;
	bool nagel;
	float nagelStrength;
	char *ringGuardType;
	float ringGuardStrength;
	bool fingerGuard;
	float fingerGuardStrength;
	
	//blade information
	char *frontShape;				//formula representing curvature of blade front
	float frontCrossSection;		//slant of front cross-section, 0 for completely flat, 1 for square edge, 100 would be a slope of 100 being basically completely edgeless
	char *backShape;				//formula representing curvature of blade back
	float backCrossSection;			//slant of back cross-section
	float pommelWeight;
	
};

#endif
