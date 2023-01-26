#include "lists.h"

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

	if (head == NULL)
		return (NULL);

	while (head)
	{
		if (head->visited == 1)
			return (NULL);
		head->visited = 1;
		head = head->next;
	}

	return (NULL);
}

