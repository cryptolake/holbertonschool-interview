#include "slide_line.h"

int testI(size_t i, int direction, size_t size)
{
	if (direction == SLIDE_LEFT)
		return (i < size);

	return (i < (size_t)-1);
}


int testJ(size_t j, int direction, size_t size)
{
	if (direction == SLIDE_LEFT)
		return (j < (size_t)-1);
	return (j < size);

}

int testK(size_t j, int direction, size_t k)
{
	if (direction == SLIDE_LEFT)
		return (j > k);

	return (j < k);

}

int slide_line(int *line, size_t size, int direction)
{
	int a = -1;
	size_t s = size-2, i, j, k = size + 1;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		a = 1;
		s = 1;
		k = 0;
	}

  for (i = s; testI(i, direction, size); i += a)
	{
			j = i;
			while (testJ(j, direction, size) && testK(j, direction, k) && line[j] != 0)
			{
					if (line[j-a] == 0)
					{
						line[j-a] = line[j];
						line[j] = 0;
					}
					else if (line[j] == line[j-a])
					{
						line[j-a] *= 2;
						line[j] = 0;
						k = j;
					}
					j -= a;
			}

	}
	return (1);
}
