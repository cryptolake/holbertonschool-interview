#include "search_algos.h"

/**
 * p_search_array - print searched array
 * @array: array to print part of
 * @l: first index
 * @r: last index
 **/
void p_search_array(int *array, size_t l, size_t r)
{
	printf("Searching in array: ");
	for (; l < r; l++)
		printf("%d, ", array[l]);
	printf("%d\n", array[l]);
}


/**
 * binary_search_rec - search array using binary search
 * @array: array to search
 * @l: beginning
 * @r: end
 * @value: value to search for
 * Return: first index of value
 **/
int binary_search_rec(int *array, size_t l, size_t r, int value)
{
	size_t mid = l + (r - l) / 2;

	p_search_array(array, l, r);
	if (l == r)
	{
		if (array[l] == value)
			return (l);
		return (-1);
	}
	if (array[mid] >= value)
		return (binary_search_rec(array, l, mid, value));
	else
		return (binary_search_rec(array, mid + 1, r, value));
}

/**
 * advanced_binary - search array using binary search
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 * Return: first index of value
 **/
int advanced_binary(int *array, size_t size, int value)
{
	/**
	 * TODO: This can be done in one function
	 * we ought to change the print function to loop by pointer
	 **/
	if (!array)

		return (-1);
	return (binary_search_rec(array, 0, size - 1, value));
}
