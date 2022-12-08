#include <stdio.h>
#include "sort.h"

/**
* swap - swap two elements
* @a: element
* @b: element
**/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* heapify - heapify array
* @arr: array
* @N: variable size of array
* @i: index
* @size: unchanging size of array
**/
void heapify(int *arr, int N, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < N && arr[left] > arr[largest])
		largest = left;

	if (right < N && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, N, largest, size);
	}
}

/**
* heap_sort - perform heap sort
* @array: array to sort
* @size: size of array
**/
void heap_sort(int *array, size_t size)
{
	int i;

	if (size == 0)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
