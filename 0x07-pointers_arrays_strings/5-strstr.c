#include "main.h"
/**
 * _strstr - Finds the first occurrence of the substring needle in
 *            the string haystack.
 * @haystack: Pointer to the string to be searched
 * @needle: Pointer to the string to be found
 *
 * Return: Pointer to the beginning of the located substring, or NULL if
 *         the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (needle[j] != haystack[i + j])
				break;
		}
		if (needle[j] == '\0')
			return (haystack + i);
	}
	return (NULL);
}
