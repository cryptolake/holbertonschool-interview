#include "sort.h"

/**
 * merge - merge both inter-arrays
 *
 * @A: main array
 * @temp: temporary array
 * @x: pointer for the start of the first array
 * @y: pointer for the end of the first array
 * @z: pointer for the end of the second array
 **/
void merge(int *A, int *temp, size_t x, size_t y, size_t z)
{
	size_t i = x, j = y + 1, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(A + x, y - x + 1);
	printf("[right]: ");
	print_array(A + y + 1, z - y);

	for (k = 0; k <= z - x; k++)
	{
		if (i > y)
			temp[k] = A[j++];
		else if (j > z)
			temp[k] = A[i++];
		else
		{
			if (A[i] < A[j])
				temp[k] = A[i++];
			else
				temp[k] = A[j++];
		}

	}

	i = 0;
	for (k = x; k <= z; k++)
		A[k] = temp[i++];

	printf("[Done]: ");
	print_array(A + x, z - x + 1);
}

/**
 * rec_merge_sort - recursive merge sort
 *
 * @array: array to sort
 * @T: temporary array
 * @x: start pointer
 * @z: end pointer
 **/
void rec_merge_sort(int *array, int *T, size_t x, size_t z)
{
	/* this is the middle pointer */
	size_t y;

	if (x >= z)
		return;

	if ((x + z) % 2)
		y = (x + z) / 2;
	else
		y = (x + z) / 2 - 1;

	/* printf("%zu %zu | %zu %zu\n", x, y, y + 1, z); */

	rec_merge_sort(array, T, x, y);
	rec_merge_sort(array, T, y + 1, z);
	merge(array, T, x, y, z);
}

/**
* merge_sort - perform merge sort
* @array: array to sort
* @size: size of array
**/
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);

	if (array != NULL)
		rec_merge_sort(array, temp, 0, size - 1);
	free(temp);
}
