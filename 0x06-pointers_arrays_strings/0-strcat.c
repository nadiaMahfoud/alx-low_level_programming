#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 *
 * Return: Pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/* Get the length of the destination string */
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Append the source string to the destination string */
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add the null terminator */
	dest[i] = '\0';

	return (dest);
}
