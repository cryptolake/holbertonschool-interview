#include "holberton.h"

int compress_wild(char *s)
{
	if (*s != '*')
		return (0);

	return (1 + compress_wild(s + 1));
}

int wildcmp(char *s1, char *s2)
{
	int wilds;
	/* if (*s1 != '\0') */
	/* 	printf("s1 == %c, s2 == %c\n", *s1, *s2); */
	if (*s1 == '\0')
	{
		if (*s2 == '\0')
			return (1);

		if (*s2 != '*' )
			return (0);

		wilds = compress_wild(s2);
		if (*s2 == '*' && *(s2 + wilds) != '\0')
			return (0);

		return (1);
	}

	if (*s2 == '*')
	{
		wilds = compress_wild(s2);
		if (*s1 == *(s2 + wilds))
		{
			/* printf("wilds = %d s1 = %c\n", wilds, *s1); */
			return (1 && (wildcmp(s1, s2 + wilds) || wildcmp(s1 + 1, s2)));

		}
		else
		{
			return (1 && wildcmp(s1 + 1, s2));

		}
	}

	else if (*s1 == *s2)
		return (1 && wildcmp(s1 + 1, s2 + 1));

	/* printf("case 2: s1 == %c, s2 == %c\n", *s1, *s2); */
	return (0);
}
