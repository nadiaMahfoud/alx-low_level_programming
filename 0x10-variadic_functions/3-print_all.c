#include "variadic_functions.h"

/**
 * print_char - Prints a character.
 * @args: The argument list.
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);

	printf("%c", c);
}

/**
 * print_integer - Prints an integer.
 * @args: The argument list.
 */
void print_integer(va_list args)
{
	int i = va_arg(args, int);

	printf("%d", i);
}

/**
 * print_float - Prints a float.
 * @args: The argument list.
 */
void print_float(va_list args)
{
	double d = va_arg(args, double);

	printf("%f", d);
}

/**
 * print_string - Prints a string.
 * @args: The argument list.
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str)
		printf("%s", str);
	else
		printf("(nil)");
}

/**
 * print_all - Prints anything.
 * @format: The format of the arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	const char *sep = "";
	void (*print_func)(va_list);

	va_start(args, format);

	while (format && format[i])
	{
		print_func = NULL;

		switch (format[i])
		{
		case 'c':
			print_func = print_char;
			break;
		case 'i':
			print_func = print_integer;
			break;
		case 'f':
			print_func = print_float;
			break;
		case 's':
			print_func = print_string;
			break;
		default:
			i++;
			continue;
		}

		printf("%s", sep);
		print_func(args);
		sep = ", ";
		i++;
	}

	va_end(args);

	printf("\n");
}
