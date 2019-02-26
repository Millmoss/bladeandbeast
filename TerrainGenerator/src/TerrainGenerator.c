#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Coordinate.c"

//int *permutation;
//int *permutationRef;
struct Coordinate **terrain;
int width;
int height;
//int repeat;

/*void shuffle()
{
	for (int i = 0; i < 256; i++)
	{
		int r = rand() % 256;
		int temp = permutation[i];
		permutation[i] = permutation[r];
		permutation[r] = temp;
	}
}

double fade(double t)
{
													// Fade function as defined by Ken Perlin.  This eases coordinate values
													// so that they will ease towards integral values.  This ends up smoothing
													// the final output.
	return t * t * t * (t * (t * 6 - 15) + 10);     // 6t^5 - 15t^4 + 10t^3
}

int inc(int num) {
    num++;
    if (repeat > 0) num %= repeat;
    
    return num;
}

// Linear Interpolate
double lerp(double a, double b, double x) {
    return a + x * (b - a);
}

double grad(int hash, double x, double y, double z)
{
    switch(hash & 0xF)
    {
        case 0x0: return  x + y;
        case 0x1: return -x + y;
        case 0x2: return  x - y;
        case 0x3: return -x - y;
        case 0x4: return  x + z;
        case 0x5: return -x + z;
        case 0x6: return  x - z;
        case 0x7: return -x - z;
        case 0x8: return  y + z;
        case 0x9: return -y + z;
        case 0xA: return  y - z;
        case 0xB: return -y - z;
        case 0xC: return  y + x;
        case 0xD: return -y + z;
        case 0xE: return  y - x;
        case 0xF: return -y - z;
        default: return 0; // never happens
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
	
	double u = fade(xf);
    double v = fade(yf);
    double w = fade(zf);
	
	int aaa, aba, aab, abb, baa, bba, bab, bbb;
    aaa = permutation[permutation[permutation[    xi ]+    yi ]+    zi ];
    aba = permutation[permutation[permutation[    xi ]+inc(yi)]+    zi ];
    aab = permutation[permutation[permutation[    xi ]+    yi ]+inc(zi)];
    abb = permutation[permutation[permutation[    xi ]+inc(yi)]+inc(zi)];
    baa = permutation[permutation[permutation[inc(xi)]+    yi ]+    zi ];
    bba = permutation[permutation[permutation[inc(xi)]+inc(yi)]+    zi ];
    bab = permutation[permutation[permutation[inc(xi)]+    yi ]+inc(zi)];
    bbb = permutation[permutation[permutation[inc(xi)]+inc(yi)]+inc(zi)];
	
	double x1, x2, y1, y2;
    x1 = lerp(    grad (aaa, xf  , yf  , zf),           // The gradient function calculates the dot product between a pseudorandom
                grad (baa, xf-1, yf  , zf),             // gradient vector and the vector from the input coordinate to the 8
                u);                                     // surrounding points in its unit cube.
    x2 = lerp(    grad (aba, xf  , yf-1, zf),           // This is all then lerped together as a sort of weighted average based on the faded (u,v,w)
                grad (bba, xf-1, yf-1, zf),             // values we made earlier.
                  u);
    y1 = lerp(x1, x2, v);

    x1 = lerp(    grad (aab, xf  , yf  , zf-1),
                grad (bab, xf-1, yf  , zf-1),
                u);
    x2 = lerp(    grad (abb, xf  , yf-1, zf-1),
                  grad (bbb, xf-1, yf-1, zf-1),
                  u);
    y2 = lerp (x1, x2, v);
    
    return (lerp (y1, y2, w)+1)/2;                      // For convenience we bind the result to 0 - 1 (theoretical min/max before is [-1, 1])

}*/

/*double planeToSphereAdjacency(int x, int y, int dir)	//finds the next coordinate on the sphere equation x = 2cos(t), y = sin(t)
{														//dir 1 through 8, 1 being north, 5 being south, 8 being west-north
	
}

void plateTectonics()
{
	//begin experimental plate gen code
	
	int plates = 20;
	int *plateStart = (int *)malloc(plates * sizeof(int));
	int ticks = 100;
	for(int i = 0;i < plates;i++)
	{
		plateStart[i] = i;//rand() % (ticks / 2);
	}
	for(int i = 0;i < ticks;i++)
	{
		for(int p = 0;p < plates;p++)
		{
			if(i == plateStart[p])
			{
				terrain[rand() % height][rand() % width] = p + 1;
			}
			if(i >= plateStart[p])
			{
				for(int y = 0;y < height;y++)
					for(int x = 0;x < width;x++)
					{
						if(terrain[y][x] == p + 1)	//modify: diagonal up-right would be up one and to the right one, then keep going right if overlap issue
						{
							fprintf(stderr, "Computing plate %d at %d,%d\n", p + 1, x, y);
							if(y != 0)							//check up
							{
								if(terrain[y-1][x] == 0 && rand() % 100 < 90)
									terrain[y-1][x] = p + 1 + plates;
								else if(terrain[y-1][x] == p + 1)
									terrain[y-1][x] += 2 * plates;
							}
							if(x != 0)							//check left
							{
								
								if(terrain[y][x-1] == 0 && rand() % 100 < 90)
									terrain[y][x-1] = p + 1 + plates;
								else if(terrain[y][x-1] == p + 1)
									terrain[y][x-1] += 2 * plates;
							}
							if(y < height - 1)					//check down
							{
								if(terrain[y+1][x] == 0 && rand() % 100 < 90)
									terrain[y+1][x] = p + 1 + plates;
								else if(terrain[y+1][x] == p + 1)
									terrain[y+1][x] += 2 * plates;
							}
							if(x < width - 1)					//check right
							{
								if(terrain[y][x+1] == 0 && rand() % 100 < 90)
									terrain[y][x+1] = p + 1 + plates;
								else if(terrain[y][x+1] == p + 1)
									terrain[y][x+1] += 2 * plates;
							}
							if(y != 0 && x != 0)				//check up left
							{
								if(terrain[y-1][x-1] == 0 && rand() % 100 < 62)
									terrain[y-1][x-1] = p + 1;
								else if(terrain[y-1][x-1] == p + 1)
									terrain[y-1][x-1] += 2 * plates;
							}
							if(x != 0 && y < height - 1)		//check down left
							{
								if(terrain[y+1][x-1] == 0 && rand() % 100 < 62)
									terrain[y+1][x-1] = p + 1 + plates;
								else if(terrain[y+1][x-1] == p + 1)
									terrain[y+1][x-1] += 2 * plates;
							}
							if(y != 0 && x < width - 1)			//check up right
							{
								if(terrain[y-1][x+1] == 0 && rand() % 100 < 62)
									terrain[y-1][x+1] = p + 1 + plates;
								else if(terrain[y-1][x+1] == p + 1)
									terrain[y-1][x+1] += 2 * plates;
							}
							if(y < height - 1 && x < width - 1)	//check down right
							{
								if(terrain[y+1][x+1] == 0 && rand() % 100 < 62)
									terrain[y+1][x+1] = p + 1 + plates;
								else if(terrain[y+1][x+1] == p + 1)
									terrain[y+1][x+1] += 2 * plates;
							}
						}
					}
				
				
				for (int y = 0; y < height; y++)
					for (int x = 0; x < width; x++)
						if(terrain[y][x] > plates && terrain[y][x] <= plates * 2)
							terrain[y][x] -= plates;
			}
		}
	}
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			if(terrain[y][x] > plates)
				terrain[y][x] -= plates;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			if(terrain[y][x] > plates)
				terrain[y][x] -= plates;
}*/

/*DllExport */void generateTerrain(int w)
{
	/*permutation = (int *)malloc(512 * sizeof(int));
	for (int i = 0; i < 256; i++)
		permutation[i] = i;
	shuffle();
	shuffle();
	shuffle();
	shuffle();
	shuffle();
	repeat = 0;
	for (int i = 256; i < 512; i++)
	{
		permutation[i] = permutation[i % 256];
	}*/
	width = w;
	height = width / 2;
	terrain = (struct Coordinate **)malloc(height * sizeof(struct Coordinate *));
	for (int y = 0; y < height; y++)
		terrain[y] = (struct Coordinate *)malloc(width * sizeof(struct Coordinate));
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			struct Coordinate c = {.plateLetter = 'X', .plateNumber = -1};
			terrain[y][x] = c;
		}
	}
	for (int y = 0; y <= height; y++)
	{
		if(y == height / 2)
			y++;
		double realHeight = abs(0 - ((double)height / 2 - (double)y));
		double diameter = 4 * sqrt(pow((double)width / 4, 2) - pow((double)realHeight, 2));
		printf("%lf\n", diameter);
		double space = width / diameter;
		for(double x = 0;x < width / 2;x += space)
		{
			if((int)round(diameter) % 2 == 0)
			{
				int tempy = y;
				if(y > height / 2)
					tempy--;
				terrain[tempy][(int)round(width / 2 + x)].plateLetter = '0';
				terrain[tempy][(int)round(width / 2 - x)].plateLetter = '0';
				terrain[tempy][(int)round(width / 2 + x)].plateNumber = 0;
				terrain[tempy][(int)round(width / 2 - x)].plateNumber = 0;
			}
			else
			{
				int tempy = y;
				if(y > height / 2)
					tempy--;
				terrain[tempy][(int)round(width / 2 + x + space / 2)].plateLetter = '0';
				terrain[tempy][(int)round(width / 2 - x - space / 2)].plateLetter = '0';
				terrain[tempy][(int)round(width / 2 + x + space / 2)].plateNumber = 0;
				terrain[tempy][(int)round(width / 2 - x - space / 2)].plateNumber = 0;
			}
		}
	}
	
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)		//this is gonna get very messy
		{
			int countx = x;
			int county = y;
			//north
			county--;
			if(county < 0)
			{
				county = 0;
				countx = (width - 1) - countx;
			}
			if(terrain[county][countx].plateNumber != 0)
			{
				if(countx < width / 2)
				{
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx++;
				}
				else
				{
					while(countx >= 0 && terrain[county][countx].plateNumber != 0)
						countx--;
				}
			}
			terrain[y][x].north = terrain[county][countx];
			countx = x;
			county = y;
			//northeast
			county--;
			if(county < 0)
			{
				county = 0;
				countx = (width - 1) - countx;
			}
			if(terrain[county][countx].plateNumber != 0)
			{
				if(countx < width / 2)
				{
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx++;
					countx++;
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx++;
				}
				else
				{
					while(countx >= 0 && terrain[county][countx].plateNumber != 0)
						countx++;
				}
			}
			terrain[y][x].northeast = terrain[county][countx];
			countx = x;
			county = y;
			//east
			while(countx < width && terrain[county][countx].plateNumber != 0)
				countx++;
			terrain[y][x].east = terrain[county][countx];
			countx = x;
			//southeast
			county++;
			if(county >= height)
			{
				county--;
				countx = (width - 1) - countx;
			}
			if(terrain[county][countx].plateNumber != 0)
			{
				if(countx < width / 2)
				{
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx++;
					countx++;
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx++;
				}
				else
				{
					while(countx >= 0 && terrain[county][countx].plateNumber != 0)
						countx++;
				}
			}
			terrain[y][x].southeast = terrain[county][countx];
			countx = x;
			county = y;
			//south
			county++;
			if(county >= height)
			{
				county--;
				countx = (width - 1) - countx;
			}
			if(terrain[county][countx].plateNumber != 0)
			{
				if(countx < width / 2)
				{
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx++;
				}
				else
				{
					while(countx >= 0 && terrain[county][countx].plateNumber != 0)
						countx--;
				}
			}
			terrain[y][x].south = terrain[county][countx];
			countx = x;
			county = y;
			//southwest
			county++;
			if(county >= height)
			{
				county--;
				countx = (width - 1) - countx;
			}
			if(terrain[county][countx].plateNumber != 0)
			{
				if(countx < width / 2)
				{
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx--;
				}
				else
				{
					while(countx >= 0 && terrain[county][countx].plateNumber != 0)
						countx--;
					countx--;
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx--;
				}
			}
			terrain[y][x].southwest = terrain[county][countx];
			countx = x;
			county = y;
			//west
			while(countx < width && terrain[county][countx].plateNumber != 0)
				countx--;
			terrain[y][x].west = terrain[county][countx];
			countx = x;
			//northwest
			county--;
			if(county < 0)
			{
				county = 0;
				countx = (width - 1) - countx;
			}
			if(terrain[county][countx].plateNumber != 0)
			{
				if(countx < width / 2)
				{
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx--;
				}
				else
				{
					while(countx >= 0 && terrain[county][countx].plateNumber != 0)
						countx--;
					countx--;
					while(countx < width && terrain[county][countx].plateNumber != 0)
						countx--;
				}
			}
			terrain[y][x].northwest = terrain[county][countx];
		}
	}
	
	//if on left side, diagonal up right or down right will go over two valid on x, opposite for right side.
	
	//plateTectonics();
}

void printTerrain()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//if(terrain[y][x] >= 0)
				printf("%d", terrain[y][x].plateNumber);
			//else
				//printf("X");
		}
		printf("\n");
	}
}

/*DllExport */int getTerrain(int x, int y)
{
	return 0;//return terrain[y][x];
}

int main(int argc, char *argv[])
{
	srand(atoi(argv[1]));
	generateTerrain(250);
	FILE *f;
	f = fopen(argv[2], "w+");
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//if(terrain[y][x] < 10)
				fprintf(f, "%c", terrain[y][x].plateLetter);
			//else
				//fprintf(f, "%d", terrain[y][x]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;
}
