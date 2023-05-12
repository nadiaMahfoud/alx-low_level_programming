#include <stdio.h>

/**
 * main - prints all arguments received
 * @argc: number of arguments received
 * @argv: array of arguments received
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}

