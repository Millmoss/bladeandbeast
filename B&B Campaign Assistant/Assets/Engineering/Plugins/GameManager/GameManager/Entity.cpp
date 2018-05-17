#include "Entity.h"

Entity::Entity()
{

}

void Entity::setName(char *n)
{
	name = (char *)malloc(64 * sizeof(char));
	strcpy_s(name, 64, n);
}

Entity::~Entity()
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