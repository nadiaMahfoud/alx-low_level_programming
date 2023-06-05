#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	size_t nbr_nodes = 0;

	while (h != NULL)
	{
		nbr_nodes++;
		h = h->next;
	}

	return (nbr_nodes);
}

