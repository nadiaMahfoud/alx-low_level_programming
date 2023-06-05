#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data,
 * elements in a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The sum of all the data elements.
 */
int sum_listint(listint_t *head)
{
	int somme = 0;
	listint_t *c;

	c = head;
	while (c != NULL)
	{
		somme += c->n;
		c = c->next;
	}

	return (sum);
}
