#include "menger.h"
#include "stdlib.h"

/* (Dumb) Dynamic Implementaion */

/**
 * remove_square - remove the central square
 * @sg: current sponge
 **/
void remove_square(sponge sg)
{
	int i, j;
	int cube_s = pow(3, sg.level - 1);

	for (i = cube_s + sg.x; i < cube_s * 2 + sg.x; i++)
	{
		for (j = cube_s + sg.y; j < cube_s * 2 + sg.y; j++)
		{
			sg.square[i][j] = ' ';
		}
	}
}

/**
 * make_menger - divide sponge to mini sponges
 * @sg: sponge
 * @level: level of the current sponge
 **/
void make_menger(sponge sg, int level)
{
	sponge spg;
	int i, j;
	int small = pow(3, level - 1);

	if (level == 0)
		return;

	spg.square = sg.square;
	spg.level = level;
	spg.x = sg.x;
	spg.y = sg.y;

	remove_square(spg);
	for (i = 0; i < 3; i++)
	{
		spg.x += i * small;
		for (j = 0; j < 3; j++)
		{
			spg.y += j * small;
			make_menger(spg, level - 1);
			spg.y -= j * small;
		}
		spg.x -= i * small;
	}
}

/**
 * menger - Print a menger Sponge
 * @level: level of the sponge
 **/
void menger(int level)
{
	int i, j;
	int size = pow(3, level);
	char **sqr;
	sponge spg;

	if (level < 0)
		return;

	sqr = malloc(sizeof(char *) * size);
	if (!sqr)
		return;

	for (i = 0; i < size; i++)
	{
		sqr[i] = malloc(sizeof(char) * (size + 1));
		if (!sqr[i])
			return;
		for (j = 0; j < size; j++)
			sqr[i][j] = '#';
		sqr[i][j] = '\0';
	}

	spg.square = sqr;
	spg.level = level;
	spg.x = 0;
	spg.y = 0;

	make_menger(spg, level);

	for (i = 0; i < size; i++)
		printf("%s\n", sqr[i]);

	for (i = 0; i < size; i++)
		free(sqr[i]);
	free(sqr);
}
