#include <stdio.h>
#include <stdlib.h>

/**
 * validate_input - Validates if the given number is composed of digits.
 * @num: The number to validate
 *
 * Return: 0 if the number is valid, 1 otherwise
 */
int validate_input(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			printf("Error\n");
			return (1);
		}
	}

	return (0);
}

/**
 * multiply_numbers - Multiplies two numbers and prints the result.
 * @num1: The first number
 * @num2: The second number
 */
void multiply_numbers(char *num1, char *num2)
{
	int len1, len2, len, i, j;
	int *result;

	len1 = 0;
	while (num1[len1] != '\0')
		len1++;

	len2 = 0;
	while (num2[len2] != '\0')
		len2++;

	len = len1 + len2;
	result = calloc(len, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		return;
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = result[i + j + 1] + mul;

			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}

	i = 0;
	while (result[i] == 0)
		i++;

	for (; i < len; i++)
		printf("%d", result[i]);
	printf("\n");

	free(result);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	if (validate_input(argv[1]) || validate_input(argv[2]))
		return (1);

	multiply_numbers(argv[1], argv[2]);

	return (0);
}
