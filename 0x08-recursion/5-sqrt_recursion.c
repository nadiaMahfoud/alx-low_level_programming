#include "main.h"
/**
 * sqrt_helper - Makes possible to evaluate from 1 to n
 * @i: same number as n
 * @j: number that iterates from 1 to n
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int sqrt_helper(int i, int j)
{
	if (j * j == i)
		return (j);
	else if (j * j > i)
		return (-1);
	return (sqrsqrt_helpert2(i, j + 1));
}
/**
 * _sqrt_recursion - returns the natural square root of n
 * @n: Number Integer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _sqrt_recursion(int n)
{
	return (sqrt_helper(n, 1));
}
