#include "main.h"

/**
 * wildcmp - Compares two strings.
 * @s1: A pointer to the first string.
 * @s2: A pointer to the second string (can contain wildcards).
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0') /* If both strings are empty */
		return (1);
	if (*s2 == '*')
	{
		if (*s1 == '\0' && *(s2 + 1) == '\0') /* If the wildcard is the last character in s2 */
			return (1);
		if (*s1 == '\0') /* If the wildcard isn't the last character in s2 and s1 is empty */
			return (0);
		if (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2)) /* Recursively check with and without matching the wildcard */
			return (1);
	}
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1)); /* Recursively check the rest of the strings */
	return (0);
}
