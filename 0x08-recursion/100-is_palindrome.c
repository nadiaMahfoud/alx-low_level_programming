#include "main.h"

/**
 * palindrome2 - obtains length of a
 * @a: string
 * @len: integer to count length
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int palindrome2(char *a, int len)
{
	if (*a == 0)
		return (len - 1);
	return (palindrome2(a + 1, len + 1));
}
/**
 * palindrome3 - compares string vs string reverse
 * @a: string
 * @len: length
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int palindrome3(char *a, int len)
{
	if (*a != *(a + len))
		return (0);
	else if (*a == 0)
		return (1);
	return (palindrome3(a + 1, len - 2));
}
/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to evaluate
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int is_palindrome(char *s)
{
	int len;

	len = palindrome2(s, 0);
	return (palindrome3(s, len));
}
