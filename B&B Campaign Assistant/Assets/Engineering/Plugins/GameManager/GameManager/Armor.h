#include <iostream>
#include <stdlib.h>
#include "Item.h"

#ifndef __ARMOR_H_INCLUDED__
#define __ARMOR_H_INCLUDED__

class Armor : Item
{
public:
	Armor();
	int getDefenseCutting();
	int getDefenseCrushing();
	int getDefenseStabbing();
protected:
	//cut defense
	int headDefenseCutting;
	int neckDefenseCutting;
	int chestDefenseCutting;
	int stomachDefenseCutting;
	int backDefenseCutting;
	int shoulderRightDefenseCutting;
	int shoulderLeftDefenseCutting;
	int upperarmRightDefenseCutting;
	int upperarmLeftDefenseCutting;
	int forearmRightDefenseCutting;
	int forearmLeftDefenseCutting;
	int handRightDefenseCutting;
	int handLeftDefenseCutting;
	int crotchDefenseCutting;
	int buttDefenseCutting;
	int thighRightDefenseCutting;
	int thighLeftDefenseCutting;
	int shinRightDefenseCutting;
	int shinLeftDefenseCutting;
	int calfRightDefenseCutting;
	int calfLeftDefenseCutting;
	int footRightDefenseCutting;
	int footLeftDefenseCutting;
	int heelRightDefenseCutting;
	int heelLeftDefenseCutting;

	//crush defense
	int headDefenseCrushing;
	int neckDefenseCrushing;
	int chestDefenseCrushing;
	int stomachDefenseCrushing;
	int backDefenseCrushing;
	int shoulderRightDefenseCrushing;
	int shoulderLeftDefenseCrushing;
	int upperarmRightDefenseCrushing;
	int upperarmLeftDefenseCrushing;
	int forearmRightDefenseCrushing;
	int forearmLeftDefenseCrushing;
	int handRightDefenseCrushing;
	int handLeftDefenseCrushing;
	int crotchDefenseCrushing;
	int buttDefenseCrushing;
	int thighRightDefenseCrushing;
	int thighLeftDefenseCrushing;
	int shinRightDefenseCrushing;
	int shinLeftDefenseCrushing;
	int calfRightDefenseCrushing;
	int calfLeftDefenseCrushing;
	int footRightDefenseCrushing;
	int footLeftDefenseCrushing;
	int heelRightDefenseCrushing;
	int heelLeftDefenseCrushing;

	//stab defense
	int headDefenseStabbing;
	int neckDefenseStabbing;
	int chestDefenseStabbing;
	int stomachDefenseStabbing;
	int backDefenseStabbing;
	int shoulderRightDefenseStabbing;
	int shoulderLeftDefenseStabbing;
	int upperarmRightDefenseStabbing;
	int upperarmLeftDefenseStabbing;
	int forearmRightDefenseStabbing;
	int forearmLeftDefenseStabbing;
	int handRightDefenseStabbing;
	int handLeftDefenseStabbing;
	int crotchDefenseStabbing;
	int buttDefenseStabbing;
	int thighRightDefenseStabbing;
	int thighLeftDefenseStabbing;
	int shinRightDefenseStabbing;
	int shinLeftDefenseStabbing;
	int calfRightDefenseStabbing;
	int calfLeftDefenseStabbing;
	int footRightDefenseStabbing;
	int footLeftDefenseStabbing;
	int heelRightDefenseStabbing;
	int heelLeftDefenseStabbing;
};

#endif
