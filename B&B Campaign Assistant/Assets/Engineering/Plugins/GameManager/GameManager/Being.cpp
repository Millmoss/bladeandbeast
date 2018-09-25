#include "Being.h"

Being::Being()
{
	name = NULL;
	type = NULL;
	walkMove = -1;
	combatMove = -1;
	runMove = -1;
	travelMove = -1;
	jumpHeight = -1;
	hands = -1;
	hand = NULL;
	weaponEquipped = NULL;
}

void Being::setName(char *n)
{
	name = (char *)malloc(64 * sizeof(char));
	strcpy_s(name, 64, n);
}

Being::~Being()
{
	if (name != NULL)
		free(name);
	if (type != NULL)
		free(type);
	if (hand != NULL)
	{
		if (hands != 0)
		{
			for (int i = 0; i < hands; i++)
				free(hand[i]);
		}
		free(hand);
	}
	if (weaponEquipped != NULL)
	{
		//need to free individual weapons?
		free(weaponEquipped);
	}
}