#include "main.h"

/**
 * _strcmp - Compare two strings.
 *
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 *
 * Return: The difference between the two strings.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}

	return (s1[i] - s2[i]);
}
