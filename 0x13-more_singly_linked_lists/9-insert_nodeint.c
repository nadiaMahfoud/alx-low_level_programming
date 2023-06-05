#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head of the linked list.
 * @idx: The index where the new node should be added.
 * @n: The value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *c;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	c = *head;
	for (i = 0; i < idx - 1; i++)
	{
		if (c == NULL)
		{
			free(new_node);
			return (NULL);
		}
		c = c->next;
	}

	new_node->next = c->next;
	c->next = new_node;

	return (new_node);
}
