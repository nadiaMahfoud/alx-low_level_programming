#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given,
 * index of a linked list.
 * @head: A double pointer to the head of the linked list.
 * @index: The index of the node to delete.
 *
 * Return: 1 if successful, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *c, *tmp;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	c = *head;
	for (i = 0; i < index - 1 && c != NULL; i++)
		c = c->next;

	if (c == NULL || c->next == NULL)
		return (-1);

	tmp = c->next;
	c->next = tmp->next;
	free(tmp);

	return (1);
}
