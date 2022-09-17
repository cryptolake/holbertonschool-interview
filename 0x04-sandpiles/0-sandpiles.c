#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * balance_sandpile - if sandpile is unblanced redistrebute
 * @grid: grid of sandpiles
 * @x: line
 * @y: row
 **/
void balance_sandpile(int grid[3][3], int x, int y)
{
	if (grid[x][y] > 3)
	{
		grid[x][y] -= 4;
		if (y != 2)
		{
			grid[x][y + 1] += 1;
		}
		if (x != 2)
		{
			grid[x + 1][y] += 1;
		}
		if (x != 0)
		{
			grid[x - 1][y] += 1;
		}
		if (y != 0)
		{
			grid[x][y - 1] += 1;
		}
	}
}

/**
 * test_sandpile - test if sandpile is stable
 * @grid: grid of sandpiles
 *
 * Return: 1 if unstable 0 if stable
 **/
int test_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
				return (1);
		}
	}

	return (0);
}

/**
 * sandpiles_sum - sum of two sandpile
 * @grid1: first and resulting grid
 * @grid2: second grid
 **/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int l1[] = {1, 1, 0, 0, 0, 2, 2, 0, 2, 2, 0, 1, 1, 0, 1, 2, 2, 1};
	int l2[] = {1, 1, 0, 1, 1, 0, 1, 2, 2, 1, 0, 0, 0, 2, 2, 0, 2, 2};
	int *l;
	int i, j, x = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (test_sandpile(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		if (x % 2 == 0)
			l = l2;
		else
			l = l1;
		for (i = 0; i < 17; i += 2)
			balance_sandpile(grid1, l[i], l[i + 1]);
		x++;
	}
}
