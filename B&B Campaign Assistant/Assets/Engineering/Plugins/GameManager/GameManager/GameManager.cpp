#include <iostream>
#include <stdlib.h>
#include "Character.h"

#define DllExport __declspec (dllexport)

DllExport int getZero()
{
	return 0;
}
