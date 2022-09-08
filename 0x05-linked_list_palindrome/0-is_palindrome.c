#include "lists.h"

/**
 * listint_len - get length of linked list
 * @h:head
 * Return: length
 *
 *
 **/
size_t listint_len(const listint_t *h)
{
	int i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}

	return (i);
}

/**
* is_palindrome - check if linked list is a palindrome
* @head: head of list
*
* Return: 1 if palindrome 0 if not
**/
int is_palindrome(listint_t **head)
{
	listint_t *p, *q;
	size_t len, x, y = 0;

	if (head == NULL)
		return (0);

	if (*head == NULL)
		return (1);

	p = *head;
	len = listint_len(p);

	while (y < len / 2)
	{
		q = p;

		for (x = y + 1; x < len - y; x++) 
			q = q->next;

		if (q->n != p->n)
			return (0);

		p = p->next;
		y++;
	}

	return (1);
}
