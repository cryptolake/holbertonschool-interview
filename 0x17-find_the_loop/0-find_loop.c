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
	listint_t *fast = head, *slow = head;

	if (head == NULL)
		return (NULL);


	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}

	return (NULL);
}

