#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words of
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}

	return count;
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: An array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int word_count;
	int word_length;
	int i, j;

	if (str == NULL || *str == '\0')
	{
		return NULL;
	}

	word_count = count_words(str);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
	{
		return NULL;
	}

	for (i = 0; i < word_count; i++)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
		{
			str++;
		}

		word_length = 0;
		while (*(str + word_length) != ' ' &&
			   *(str + word_length) != '\t' &&
			   *(str + word_length) != '\n' &&
			   *(str + word_length) != '\0')
		{
			word_length++;
		}

		words[i] = malloc(sizeof(char) * (word_length + 1));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(words[j]);
			}
			free(words);
			return NULL;
		}

		for (j = 0; j < word_length; j++)
		{
			words[i][j] = *(str++);
		}
		words[i][j] = '\0';
	}

	words[i] = NULL;

	return words;
}
