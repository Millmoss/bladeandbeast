#include <iostream>
#include <stdlib.h>
#include "ItemList.h"

#ifndef __BEING_H_INCLUDED__
#define __BEING_H_INCLUDED__

class Being
{
	public:
		Being();							//does literally nothing
		void setName(char *n);				//sets the name
		~Being();							//frees all memory
	protected:
		char *name;							//name
		char *type;							//being type
		int travelMove;						//usual speed in miles per eight hours of walking or a normal day of travel
		int walkMove;						//speed when walking
		int combatMove;						//speed in combat
		int runMove;						//speed while sprinting
		float jumpHeight;					//height of jump from standing under standard conditions
		int hands;							//number of hands that are functionally human
		char **hand;						//hand identifier (human would have 0 be "Left" and 1 be "Right"
		Weapon *weaponEquipped;				//weapon in corresponding hand
};

#endif
