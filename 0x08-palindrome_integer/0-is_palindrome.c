#include "palindrome.h"


/**
* poww - get power
* @x: number
* @y: exponant
* Return: Result
**/
unsigned long poww(unsigned long x, unsigned long y)
{
	if (y == 1)
		return (x);
	return (x * poww(x, y - 1));
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
	tlen = poww(10, len - 1);

	if ((unsigned long)(n / tlen) == (unsigned long)(n % 10))
		return (is_palindrome(n % tlen / 10));
	return (0);
}
