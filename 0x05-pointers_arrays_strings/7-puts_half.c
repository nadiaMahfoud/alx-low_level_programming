#include "main.h"
#include <string.h>

/**
 * puts_half - Prints the second half of a string
 * @str: The string to be printed
 *
 * Return: void
 */
void puts_half(char *str)
{
	int length = strlen(str);
	int i, n;

	if (length % 2 == 0)
	{
		n = length / 2;
	}
	else
	{
		n = (length - 1) / 2;
	}

	for (i = n; i < length; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
