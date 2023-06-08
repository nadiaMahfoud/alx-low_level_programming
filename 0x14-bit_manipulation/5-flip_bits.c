#include "main.h"

/**
 * flip_bits - Counts the number of bits needed
 * to flip to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int val = n ^ m;
	unsigned int count = 0;

	while (val != 0)
	{
		if ((val & 1) == 1)
			count++;
		val = val >> 1;
	}
	return (count);
}
