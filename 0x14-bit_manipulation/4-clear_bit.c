#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number.
 * @index: Index of the bit to clear.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int a;
	unsigned int b;

	if (index > 64)
		return (-1);
	b = index;
	for (a = 1; b > 0; a *= 2, b--)
		;

	if ((*n >> index) & 1)
		*n -= a;

	return (1);
}
