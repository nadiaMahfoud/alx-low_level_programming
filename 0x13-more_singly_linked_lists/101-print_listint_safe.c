#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list (safe version).
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = NULL;
	const listint_t *runner = NULL;
	size_t count = 0;
	size_t position;

	current = head;
	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
		runner = head;
		position = 0;
		while (position < count)
		{
			if (current == runner)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (count);
			}
			runner = runner->next;
			position++;
		}
		if (!head)
			exit(98);
	}
	return (count);
}
