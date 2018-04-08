#include <iostream>
#include <stdlib.h>
#include "Character.h"

#define DllExport __declspec (dllexport)

Character character;

extern "C" DllExport void createCharacter(char *name);

extern "C" DllExport void setStrength(int s);

extern "C" DllExport int getStrength();
