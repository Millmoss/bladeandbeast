#include <iostream>
#include <stdlib.h>

#ifndef __ITEM_H_INCLUDED__
#define __ITEM_H_INCLUDED__

class Item
{
public:
	Item();						//
	~Item();
protected:
	std::string name;			//name
	float weight;				//weight
	float price;				//price
	std::string description;	//description of the item
	float durability;			//number representing the amount of "health" the functional portion of the item has. higher numbers are better. when this reaches 0 the item is unusable
};

#endif
