#include "lists.h"

/*
* intsert_node - insert node into head
* @head: head of linked list
* @number: number to insert
**/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *h;
	listint_t *old;
	listint_t *new_node;
	
	if (head == NULL) {
		return NULL;
	}

	new_node = malloc(sizeof(listint_t));

	h = *head;

	if (h == NULL) {
		new_node->n = number;
		new_node->next = NULL;
		*head = new_node;
		return new_node;
	}

	while (h->next && h->next->n < number)
		h = h->next;

	if (h == *head) {
		*head = new_node;
		new_node->n = number;
		new_node->next = h;
		return new_node;
	}

	old = h->next;
	h->next = new_node;
	new_node->next = old;
	new_node->n = number;
	return new_node;
}
