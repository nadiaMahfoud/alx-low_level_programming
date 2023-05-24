#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 on success, 1 on incorrect number of arguments,
 *         or 2 on negative number of bytes.
 */
int main(int argc, char *argv[])
{
	int bytes, a;
	unsigned char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	ptr = (unsigned char *)main;
	for (a = 0; a < bytes; a++)
	{
		printf("%02x", *(ptr + a));
		if (a != bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}

