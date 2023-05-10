#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number to compute its factorial
 *
 * Return: the factorial of n, or -1 if n is negative
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
