#include "main.h"
/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of n, or -1 if n does not have a natural
 *         square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (helper(1, n, n));
}

/**
 * helper - Finds the natural square root of a number.
 * @low: The lowest possible square root of n.
 * @high: The highest possible square root of n.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of n, or -1 if n does not have a natural
 *         square root.
 */
int helper(int low, int high, int n)
{
	int mid;

	if (low > high)
		return (-1);
	mid = (low + high) / 2;
	if (mid * mid == n)
		return (mid);
	if (mid * mid > n)
		return (helper(low, mid - 1, n));
	return (helper(mid + 1, high, n));
}
