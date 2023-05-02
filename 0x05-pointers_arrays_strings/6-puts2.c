#include "main.h"

/**
 * puts2 - prints one char out of 2 of a string
 * @str: input string
 *
 * Return: void
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i += 2)
		_putchar(str[i]);
	_putchar('\n');
}
