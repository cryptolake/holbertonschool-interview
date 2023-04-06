#include "sort.h"

/**
 * get_max - find max value in array
 * @array: array to find max
 * @size: size of array
 *
 * Return: max value
 **/
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - counting sort
 *
 * @array: array to sort
 * @size: size of array
 * @radix: radix to the power of 10
 *
 * Return: sorted array accoding to radix
 **/
void counting_sort(int *array, size_t size, int radix)
{
	int *count, *temp;
	ssize_t j;
	size_t i;


	count = malloc(sizeof(int) * 10);
	if (!count)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / radix) % 10] += 1;
		temp[i] = 0;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		temp[count[(array[j] / radix) % 10] - 1] = array[j];
		count[(array[j] / radix) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
	free(count);
}


/**
* radix_sort - radix sort
* @array: array to sort
* @size: size of array
**/
void radix_sort(int *array, size_t size)
{
	int radix = 1, max = get_max(array, size);

	if (array == NULL)
		return;

	if (size == 1)
		return;

	while (max != 0)
	{
		counting_sort(array, size, radix);
		print_array(array, size);
		radix *= 10;
		max /= 10;
	}

}
