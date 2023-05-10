#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of n
 * @n: input number
 *
 * Return: natural square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	else
		return (sqrt_helper(n, 1));
}

/**
 * sqrt_helper - helper function to find the square root of n
 * @n: input number
 * @i: iterator
 *
 * Return: natural square root of n, or -1 if n does not have a natural square root
 */
int sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	else if (i * i > n)
		return (-1);
	else
		return (sqrt_helper(n, i + 1));
}
