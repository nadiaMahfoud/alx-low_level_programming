#include "main.h"
/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	/* check for base cases */
	if (n < 2)
		return (0);
	if (n == 2 || n == 3)
		return (1);

	/* check if n is divisible by 2 or 3 */
	if (n % 2 == 0 || n % 3 == 0)
		return (0);

	return (is_prime_helper(n, 5));
}

/**
 * is_prime_helper - helper function for is_prime_number
 * @n: the number to check
 * @i: the current divisor to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_helper(int n, int i)
{
	/* check if i is greater than the square root of n */
	if (i * i > n)
		return (1);

	/* check if n is divisible by i */
	if (n % i == 0)
		return (0);

	/* try the next odd divisor */
	return (is_prime_helper(n, i + 2));
}
