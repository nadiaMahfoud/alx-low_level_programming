#include "main.h"

/**
 * leet - encodes a string into 1337.
 *
 * @str: the string to encode.
 *
 * Return: a pointer to the encoded string.
 */
char *leet(char *str)
{
	char *letters = "aAeEoOtTlL";
	char *leet_chars = "4433007711";
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; letters[j]; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = leet_chars[j];
				break;
			}
		}
	}
	return (str);
}
