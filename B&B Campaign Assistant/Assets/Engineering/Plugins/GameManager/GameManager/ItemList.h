#include "Sword.h"
#include <unordered_map>

#ifndef __ITEMLIST_H_INCLUDED__
#define __ITEMLIST_H_INCLUDED__

class ItemList
{
public:
	ItemList();													//
	~ItemList();												//
	int weapons;												//
	std::unordered_map<char *, Weapon> weaponMap;				//contains all weapons, can have weapons be added to it so long as they are uniquely named
	char **weaponList;											//contains all weapon names in alphabetical order
};

#endif
