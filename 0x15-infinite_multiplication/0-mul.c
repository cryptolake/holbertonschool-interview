#include "holberton.h"
#include <stdio.h>

/**
 * _strlen - get length of string
 *
 * @s: string
 *
 * Return: length
 **/
size_t _strlen(char *s)
{
	size_t i = 0;

	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
* make_num - make array out of string of numbers
* @num: string
* Return: array of integers
**/
int *make_num(char *num)
{
	ssize_t len = _strlen(num);
	ssize_t i;
	int *array_num;

	array_num = malloc(sizeof(int) * len);
	if (!array_num)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (NULL);
		array_num[i] = num[i] - '0';
	}
	return (array_num);
}

/**
* calculate - calculate the product of two arrays of integers
* @num1: first number
* @num2: second number
* @n1: length of first number
* @n2: length of second number
*
* Return: struct of result with its length and overflow
**/
res calculate(int *num1, int *num2, ssize_t n1, ssize_t n2)
{
	ssize_t n = n1 + n2 - 1, i, j;
	int dec, dig;
	res num;

	num.over = 0;
	num.num = malloc(n * sizeof(int));
	if (!num.num)
		return (num);
	for (i = 0; i < n; i++)
		num.num[i] = 0;
	num.len = n;
	for (i = n1 - 1; i > -1; i--)
	{
		for (j = n2 - 1; j > -1; j--)
		{
			num.num[i + j] += num1[i] * num2[j];
		}
	}

	for (i = n; i > -1; i--)
	{
		dig = num.num[i] % 10;
		dec  = num.num[i] / 10;
		if (dec != 0)
		{
			if (i - 1 == -1)
			{
				num.over = dec;
			}
			else
				num.num[i - 1] += dec;
			num.num[i] = dig;
		}
	}
	return (num);
}

/**
 * _puts - print string to stdout
 *
 * @str: string
 **/
void _puts(char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		_putchar(str[i++]);
	_putchar('\n');
}

/**
* main - main function to run
* @argc: number of arguments
* @argv: arguments
* Return: status code
**/
int main(int argc, char *argv[])
{
	ssize_t i;
	int *num1, *num2;
	res num;

	if (argc != 3)
	{
		_puts("Error");
		return (98);
	}

	num1 = make_num(argv[1]);
	num2 = make_num(argv[2]);
	if (num1 == NULL || num2 == NULL)
	{
		_puts("Error");
		return (98);
	}
	num = calculate(num1, num2, _strlen(argv[1]), _strlen(argv[2]));
	if (num.num == NULL)
	{
		_puts("Error");
		return (98);
	}
	if (num.over != 0)
		_putchar(num.over + '0');
	for (i = 0; i < num.len; i++)
		_putchar(num.num[i] + '0');
	_putchar('\n');
	free(num.num);
	free(num1);
	free(num2);

	return (0);
}
