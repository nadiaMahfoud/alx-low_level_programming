#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int s1_length = 0, s2_length = 0, concat_length = 0;
	char *concatenated_str, *ptr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[s1_length] != '\0')
		s1_length++;
	while (s2[s2_length] != '\0')
		s2_length++;

	concat_length = s1_length + s2_length;

	concatenated_str = malloc((concat_length + 1) * sizeof(char));
	if (concatenated_str == NULL)
		return (NULL);

	ptr = concatenated_str;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	while (*s2 != '\0')
		*ptr++ = *s2++;

	*ptr = '\0';

	return (concatenated_str);
}
