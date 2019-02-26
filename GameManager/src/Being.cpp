#include "Being.h"

Being::Being()
{
	name = "NULL";
	type = "NULL";
	walkMove = -1;
	combatMove = -1;
	runMove = -1;
	travelMove = -1;
	jumpHeight = -1;
	hands = -1;
	hand = NULL;
	weaponEquipped = NULL;
}

void Being::setName(std::string n)
{
	name = n;
}

Being::~Being()
{
	if (hand != NULL)
	{
		free(hand);
	}
	if (weaponEquipped != NULL)
	{
		//need to free individual weapons?
		free(weaponEquipped);
	}
}