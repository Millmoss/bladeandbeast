#include <iostream>
#include <stdlib.h>
#include "ItemList.h"

#ifndef __BEING_H_INCLUDED__
#define __BEING_H_INCLUDED__

class Being
{
	public:
		Being();							//does literally nothing
		void setName(std::string n);		//sets the name
		~Being();							//frees all memory
	protected:
		std::string name;					//name
		std::string type;					//being type
		int travelMove;						//usual movespeed in miles per eight hours of walking or a normal day of travel
		int walkMove;						//movespeed when walking
		int combatMove;						//movespeed in combat
		int runMove;						//movespeed while sprinting
		float jumpHeight;					//height of jump from standing under standard conditions
		int hands;							//number of hands that are functionally human
		std::string *hand;					//hand identifier (human would have 0 be "Left" and 1 be "Right"
		Weapon *weaponEquipped;				//weapon in corresponding hand
};

#endif
