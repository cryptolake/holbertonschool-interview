#include "search.h"

/**
 * get_last - get last index
 * @list: the list
 * Return: the last index
 **/
size_t get_last(skiplist_t *list)
{
	skiplist_t *node = list;
	size_t index = 0;

	/* this is dumb but we need to get the size.*/
	while (node != NULL)
	{
		index = node->index;
		node = node->next;
	}
	return (index);
}

/**
* linear_skip - search in skip list
* @list: the skip list
* @value: the value to search
* Return: the pointer of the node with value
**/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int exp = 1;
	skiplist_t *nodexp = list;

	while (list != NULL)
	{
		nodexp = list->express;
		if (exp)
		{
			if (nodexp != NULL)
			{
				printf("Value checked at index [%lu] = [%d]\n", nodexp->index, nodexp->n);
				if (nodexp->n >= value)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, nodexp->index);
					exp = 0;
				}
			}
			else
			{
				printf("Value found between indexes [%lu] and [%lu]\n",
				list->index, get_last(list));
				exp = 0;
			}
		}
		if (exp != 1)
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
		if (exp)
			list = nodexp;
		else
			list = list->next;
	}
	return (NULL);
}
