#include "search_algos.h"

/**
  * linear_search - function to look for a value in an arrray of integers
  * @array: ptr to the first element  in the array.
  * @size: number of elements in the array.
  * @value: Value to search for.
  * Return: (-1) If value is not in array or array is NULL.
  *         Otherwise, first index of value
  * Description: Print each value in the array as it gets compared.
  */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
