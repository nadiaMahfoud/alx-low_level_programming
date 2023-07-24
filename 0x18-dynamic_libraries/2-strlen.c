#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: string whose length is to be determined
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}
