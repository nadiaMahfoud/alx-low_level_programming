#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to a new string containing the concatenated arguments
 * or NULL if ac == 0 or av == NULL or if memory allocation fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, len;
	int total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			len++;
			total_len++;
		}
		total_len++;
	}

	str = malloc((total_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
			str[k++] = av[i][j++];
		str[k++] = '\n';
	}

	str[k] = '\0';

	return (str);
}
