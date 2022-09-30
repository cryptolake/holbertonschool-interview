#include "palindrome.h"

/**
 * ipow - get power
 * @base: number
 * @exp: exponant
 * Return: Result
 **/
unsigned long ipow(unsigned long base, unsigned long exp)
{
	unsigned long result = 1;

	for (;;)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		if (!exp)
			break;
		base *= base;
	}

	return (result);
}

/**
 * is_palindrome - test whether n is a palindrome
 * @n: the number to test
 * Return: 1 if palindrome 0 if not
 **/
int is_palindrome(unsigned long n)
{
	int len = snprintf(NULL, 0, "%lu", n);
	unsigned long tlen;

	if (len == 1)
		return (1);
	tlen = ipow(10, len - 1);

	if ((unsigned long)(n / tlen) == (unsigned long)(n % 10))
		return (is_palindrome(n % tlen / 10));
	return (0);
}
