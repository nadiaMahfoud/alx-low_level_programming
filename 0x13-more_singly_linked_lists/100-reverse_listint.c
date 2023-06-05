#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A double pointer to the head of the linked list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *c = *head;
	listint_t *next;

	while (c != NULL)
	{
		next = c->next;
		c->next = prev;
		prev = c;
		c = next;
	}

	*head = prev;
	return (*head);
}
