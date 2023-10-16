#ifndef MENGER
#define MENGER
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

void menger(int level);


/**
* struct sponge - struct of a sponge
*
* @x: the x coordinate of the top-left position
* @y: the y coordinate
* @square: the sponge itself
* @level: the sponge level
**/
typedef struct sponge
{
	int level;
	char **square;
	int x;
	int y;
} sponge;

#endif
