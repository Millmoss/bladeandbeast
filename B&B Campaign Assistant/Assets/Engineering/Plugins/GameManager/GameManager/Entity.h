#include <iostream>
#include <stdlib.h>
#include "ItemList.h"

#ifndef __ENTITY_H_INCLUDED__
#define __ENTITY_H_INCLUDED__

class Entity
{
	public:
		Entity();							//does literally nothing
		void SetName(char *n);				//sets the name
		~Entity();							//frees all memory
	protected:
		char *name;							//name
		char *type;							//being type
		int travelSpeed;					//usual speed in miles per eight hours of walking or a normal day of travel
		int walkSpeed;						//speed when walking
		int combatSpeed;					//speed in combat
		int runSpeed;						//speed while sprinting
		int hands;							//number of hands that are functionally human
		char **hand;						//hand identifier (human would have 0 be "Left" and 1 be "Right"
		Weapon *weaponEquipped;			//weapon in corresponding hand
};

#endif
