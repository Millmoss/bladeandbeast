#include "Entity.h"

Entity::Entity()
{

}

void Entity::setName(char *n)
{
	char *n2 = (char *)malloc(sizeof(char) * 32);
	strcpy_s(n2, 32, n);
	name = n2;
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