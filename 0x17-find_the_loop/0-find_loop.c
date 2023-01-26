#include "lists.h"

/**
* key_index - use this hash function for all the next tasks
* @key: key to retrieve index
* @size: size of table
*
* Return: index in table
**/
unsigned int key_index(size_t key, unsigned long int size)
{
	int index;

	key = (key ^ 61) ^ (key >> 16);
	key = key + (key << 3);
	key = key ^ (key >> 4);
	key = key * 0x27d4eb2d;
	key = key ^ (key >> 15);

	index = key % size;

	return (index);
}


/**
* find_listint_loop - find loop in linked list
* using hash table
*
* @head: head of linked list
*
* Return: start of the loop or NULL if none
**/
listint_t *find_listint_loop(listint_t *head)
{
	unsigned int index, i, hash_table[10000];
	listint_t *node = head;

	for (i = 0; i < 10000; i++)
		hash_table[i] = 0;
	if (node == NULL)
		return (NULL);

	while (node)
	{
		index = key_index((size_t)node, 10000);
		if (hash_table[index])
			return (node);
		hash_table[index] = 1;
		node = node->next;
	}

	return (NULL);
}

