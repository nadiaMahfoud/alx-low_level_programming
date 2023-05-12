#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	int i, sum = 0, num;

	if (argc == 1)
	{
		printf("%d\n", 0);
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		num = atoi(argv[i]);

		if (num == 0 && *argv[i] != '0')
		{
			printf("Error\n");
			return (1);
		}

		if (num < 0)
		{
			printf("%d\n", sum);
			return (0);
		}
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}
