#include "menger.h"
/* Math implementation */

/**
 * choose_char - choose the right caracter
 * @a:  is th column
 * @b: is the row
 * Return: ' ' or '#'
 */
char choose_char(int a, int b)
{
	for (; a && b; a /= 3, b /= 3)
		if (a % 3 == 1 && b % 3 == 1)
			return (' ');
	return ('#');
}

/**
 * menger - print  menger
 * @level: the size
 */
void menger(int level)
{
	int size, i, j;

	if (level >= 0)
	{
		size = pow(3, level);
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				printf("%c", choose_char(i, j));
			printf("\n");
		}
	}
}
