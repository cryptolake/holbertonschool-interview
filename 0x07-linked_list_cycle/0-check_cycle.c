#include "lists.h"

int check_cycle(listint_t *list)
{
	listint_t *p = list, *pp = list;

	while (p)
	{
		if (p->next == p)
			return (1);
		while (pp != p)
		{
			if (p->next == pp)
				return (1);

			pp = pp->next;
		}
		p = p->next;
		pp = list;
	}
	return (0);
}
