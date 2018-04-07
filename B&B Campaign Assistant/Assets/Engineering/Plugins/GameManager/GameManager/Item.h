#include <iostream>
#include <stdlib.h>

#ifndef __ITEM_H_INCLUDED__
#define __ITEM_H_INCLUDED__

class Item
{
public:
	Item();				//      
	~Item();
protected:
	char *name;			//name
	float weight;		//weight
	int price;			//price
	char *description;	//description of the item
	char *function;		//function of the item
};

#endif
