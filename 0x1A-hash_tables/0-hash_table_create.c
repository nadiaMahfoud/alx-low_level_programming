/*
 * File: 0-hash_table_create.c
 * Auth :Nadia M
 */

#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table with a given size
 *
 * @size: size of the hash table
 * Return: the created hash table, or NULL if function fails
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ptr;
	unsigned long int i;

	ptr = malloc(sizeof(hash_table_t));
	if (ptr == NULL)
		return (NULL);

	ptr->size = size;
	ptr->array = malloc(sizeof(hash_node_t *) * size);
	if (ptr->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ptr->array[i] = NULL;

	return (ptr);
}
