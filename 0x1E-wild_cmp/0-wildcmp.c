#include "holberton.h"

/**
* compress_wild - get number of * from current location
* @s: pointer to char in the string
* Return: number of *
**/
int compress_wild(char *s)
{
	if (*s != '*')
		return (0);

	return (1 + compress_wild(s + 1));
}

/**
* wildcmp - compare two strings considering the wild symbol *
* @s1: string to get match for
* @s2: matching string
* Return: 1 matched, 0 unmatched
**/
int wildcmp(char *s1, char *s2)
{
	int wilds;

	if (*s1 == '\0')
	{
		if (*s2 == '\0')
			return (1);

		if (*s2 != '*')
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
			return (1 && (wildcmp(s1, s2 + wilds) || wildcmp(s1 + 1, s2)));
		else
			return (1 && wildcmp(s1 + 1, s2));

	}

	else if (*s1 == *s2)
		return (1 && wildcmp(s1 + 1, s2 + 1));

	return (0);
}
