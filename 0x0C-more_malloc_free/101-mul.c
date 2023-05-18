#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - tells if the string consists of digits
 * @argv: pointer to current item in argument
 * Return: return 0 if all digits, 1 if not all digits.
 */
int _isdigit(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

/**
 * main - multiply two big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 * Return: return 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int i;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 1; i < argc; i++)
	{
		if (_isdigit(argv[i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (0);
}
