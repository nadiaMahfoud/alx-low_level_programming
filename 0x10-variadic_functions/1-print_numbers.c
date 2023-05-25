#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numb;
	unsigned int i;

	va_start(numb, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(numb, int));
		if (separator && i < n - 1)
			printf("%s", separator);
	}
	va_end(numb);

	printf("\n");
}
