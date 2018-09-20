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
		int travelSpeed;					//usual speed in miles per eight hours of walking or a normal day of travel
		int walkSpeed;						//speed when walking
		int combatSpeed;					//speed in combat
		int runSpeed;						//speed while sprinting
		int hands;							//number of hands that are functionally human
		char **hand;						//hand identifier (human would have 0 be "Left" and 1 be "Right"
		Weapon *weaponEquipped;				//weapon in corresponding hand
};

#endif
