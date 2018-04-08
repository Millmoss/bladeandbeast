#include <iostream>
#include <stdlib.h>
#include "Character.h"
#include "GameManager.h"

Character character;

DllExport void createCharacter(char *name)
{
	character.setName(name);
}

DllExport void setStrength(int s)
{
	character.setStrength(s);
}

DllExport int getStrength()
{
	return character.getStrength();
}
