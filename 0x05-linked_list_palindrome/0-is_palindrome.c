#include "lists.h"


/**
* is_palindrome - check if linked list is a palindrome
* @head: head of list
*
* Return: 1 if palindrome 0 if not
**/
int is_palindrome(listint_t **head)
{
	listint_t *temp, *node;

	if (head == NULL)
		return (1);

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	node = *head;
	while (node->next)
	{
		node = node->next;
	}
	temp = *head;
	while (node >= temp)
	{
		if (temp->n == node->n)
		{
			temp = temp->next;
			node -= 2;
		}
		else
			return (0);
	}
	return (1);
}
