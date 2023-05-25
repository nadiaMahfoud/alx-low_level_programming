#include "variadic_functions.h"

/**
 * print_all - Prints anything.
 * @format: The format of the arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char c;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			c = va_arg(args, int);
			printf("%c", c);
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			break;
		case 's':
			str = va_arg(args, char *);
			if (str)
				printf("%s", str);
			else
				printf("(nil)");
			break;
		default:
			i++;
			continue;
		}

		if (format[i + 1])
			printf(", ");

		i++;
	}

	va_end(args);

	printf("\n");
}
