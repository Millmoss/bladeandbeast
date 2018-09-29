#include <stdlib.h>
#include <stdio.h>

struct Coordinate
{
	char plateLetter;
	int plateNumber;
	
	struct Coordinate *north;
	struct Coordinate *northeast;
	struct Coordinate *east;
	struct Coordinate *southeast;
	struct Coordinate *south;
	struct Coordinate *southwest;
	struct Coordinate *west;
	struct Coordinate *northwest;
	
	
};

struct CoordinateCycler
{
	
};
