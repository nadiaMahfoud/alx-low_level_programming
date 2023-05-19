#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _strlength - returns the length of a string.
 * @str: string whose length is to be determined
 *
 * Return: length of the string
 */
int _strlength(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * _isdigit - checks if a character is a digit.
 * @c: character to be checked
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * errors - handles errors for main.
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * print_result - prints the result array.
 * @result: the result array
 * @len: the length of the result array
 */
void print_result(int *result, int len)
{
	int i;
	int isNonZero = 0;

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			isNonZero = 1;

		if (isNonZero)
			_putchar(result[i] + '0');
	}

	if (!isNonZero)
		_putchar('0');

	_putchar('\n');
}

/**
 * main - multiplies two big number strings.
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i, carry, digit1, digit2, *result;

	num1 = argv[1];
	num2 = argv[2];

	if (argc != 3 || !_isdigit(*num1) || !_isdigit(*num2))
		errors();

	len1 = _strlength(num1);
	len2 = _strlength(num2);
	len = len1 + len2 + 1;

	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);

	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = num1[len1] - '0';
		carry = 0;

		for (len2 = _strlength(num2) - 1; len2 >= 0; len2--)
		{
			digit2 = num2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}

	print_result(result, len);
	free(result);
	return (0);
}
