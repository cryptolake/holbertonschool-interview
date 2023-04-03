#include "list.h"

/**
* add_node_end - add node to the end of
* circular linked list
* @list: list to add to
* @str: data to add
* Return: address of new node or NULL if fail
**/
List *add_node_end(List **list, char *str)
{
	List *end, *begin, *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	new->str = str;
	if (*list == NULL)
	{
		*list = new;
		new->next = new;
		new->prev = new;
		return (new);
	}

	begin = *list;
	end = begin->prev;


	new->next = begin;
	new->prev = end;

	end->next = new;
	begin->prev = new;
	
	return (new);
}

/**
* add_node_begin - add node to the begining of
* circular linked list
* @list: list to add to
* @str: data to add
* Return: address of new node or NULL if fail
**/
List *add_node_begin(List **list, char *str)
{
	List *end, *begin, *new;

	if (list == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	new->str = str;
	if (*list == NULL)
	{
		*list = new;
		new->next = new;
		new->prev = new;
		return (new);
	}

	begin = *list;
	end = begin->prev;
	

	new->next = begin;
	new->prev = end;

	end->next = new;
	begin->prev = new;
	*list = new;

	return (new);
}
