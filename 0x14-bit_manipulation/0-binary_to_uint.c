#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is one or more chars
 * in the string b that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal;
	unsigned int j;

	for (decimal = 0, j = 0; b[j] != '\0'; j++)
	{
		if (b[j] == '1')
			decimal = (decimal << 1) | 1;
		else if (b[j] == '0')
			decimal <<= 1;
		else if (b[j] != '0' && b[j] != '1')
			return (0);
	}

	return (decimal);
}
