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
	int n;

	if (*needle == 0)
		return (haystack);

	while (*haystack)
	{
		n = 0;

		if (haystack[n] == needle[n])
		{
			do {
				if (needle[n + 1] == '\0')
					return (haystack);
				n++;
			} while (haystack[n] == needle[n]);
		}
		haystack++;
	}
	return ('\0');
}
