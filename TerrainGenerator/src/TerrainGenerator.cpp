#include <iostream>

#define DllExport __declspec (dllexport)

extern "C"
{
	#include <stdlib.h>

	int *permutation;
	int **terrain;
	int width;
	int height;
	int repeat;

	void shuffle(int *toShuffle)
	{
		for (int i = 0; i < 256; i++)
		{
			int r = rand() % 256;
			int temp = toShuffle[i];
			toShuffle[i] = toShuffle[r];
			toShuffle[r] = temp;
		}
	}

	double perlinNoise(int x, int y, int z)
	{
		if (repeat > 0) {                                    // If we have any repeat on, change the coordinates to their "local" repetitions
			x = x % repeat;
			y = y % repeat;
			z = z % repeat;
		}

		int xi = (int)x & 255;                              // Calculate the "unit cube" that the point asked will be located in
		int yi = (int)y & 255;                              // The left bound is ( |_x_|,|_y_|,|_z_| ) and the right bound is that
		int zi = (int)z & 255;                              // plus 1.  Next we calculate the location (from 0.0 to 1.0) in that cube.
		double xf = x - (int)x;
		double yf = y - (int)y;
		double zf = z - (int)z;
	}

	DllExport void generateTerrain(int x, int y)	//gets all terrain info by generating altitude data and 
	{
		permutation = (int *)malloc(512 * sizeof(int));
		for (int i = 0; i < 256; i++)
			permutation[i] = i;
		shuffle(permutation);
		shuffle(permutation);
		shuffle(permutation);
		shuffle(permutation);
		shuffle(permutation);
		for (int i = 256; i < 512; i++)
			permutation[i] = permutation[i % 256];

		terrain = (int **)malloc(y * sizeof(int *));
		for (int i = 0; i < y; i++)
			terrain[i] = (int *)malloc(x * sizeof(int));
		for (int i = 0; i < y; i++)
			for (int ii = 0; ii < x; ii++)
				terrain[i][ii] = 0;
		width = x;
		height = y;
		repeat = 0;
	}

	DllExport int getTerrain(int x, int y)
	{
		return terrain[y][x];
	}
}