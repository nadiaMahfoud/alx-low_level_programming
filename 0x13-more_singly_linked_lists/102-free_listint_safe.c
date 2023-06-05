#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a list safely
 * @h: Double pointer to the head of the list
 *
 * Return: Size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *c = *h;
	listint_t *next;
	size_t count = 0;

	while (c)
	{
		count++;
		next = c->next;
		free(c);
		if (next >= c)
		{
			*h = NULL;
			return (count);
		}
		c = next;
	}
	*h = NULL;
	return (count);
}
