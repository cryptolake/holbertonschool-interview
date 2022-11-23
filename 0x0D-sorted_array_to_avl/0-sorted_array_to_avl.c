#include "binary_trees.h"

/**
* fill_avl_tree - fill tree from array recusively
* @array: array to fill from
* @leaf: current leaf to fill
* @parent: parent of leaf
* @size: size of array
* @index: the index of the element to currently put
* @check: array to check if the element is added
*
* Return: 0 if success 1 if not
**/
avl_t *fill_avl_tree(int *array, avl_t *leaf, avl_t *parent,
										 size_t size, size_t index, int *check)
{
	size_t left = index - (size - index) / 2,
	right = index + (size - index) / 2;

	if (left == right)
	{
		leaf->n = array[index];
		leaf->parent = parent;
		leaf->right = NULL;
		leaf->left = NULL;
		return (leaf);
	}

	leaf->n = array[index];
	check[index] = 1;
	leaf->parent = parent;

	if (!check[left])
	{
		leaf->left = malloc(sizeof(avl_t));
		if (leaf->left == NULL)
			return (NULL);
		fill_avl_tree(array, leaf->left, leaf, index,	left, check);
	}
	else
	{
		leaf->left = NULL;
	}
	if (!check[right])
	{
		leaf->right = malloc(sizeof(avl_t));
		if (leaf->right == NULL)
			return (NULL);
		fill_avl_tree(array, leaf->right, leaf, size,	right, check);
	}
	else
	{
		leaf->left = NULL;
	}
	return (leaf);
}

/**
* sorted_array_to_avl - sorted array to avl
* @array: array
* @size: size of array
* Return: head of avl
**/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head, *test;
	int check[size];
	size_t i;

	for (i = 0; i < size; i++)
		check[i] = 0;
	head = malloc(sizeof(avl_t));
	if (!head)
		return (NULL);
	test = fill_avl_tree(array, head, NULL, size, (size - 1) / 2, check);
	if (test == NULL)
		return (NULL);

	return (head);
}
