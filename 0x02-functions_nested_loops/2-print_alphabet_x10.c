#include"main.h"

/**
 * print_alphabet_x10 - function that print 10 line with alphabet
 * Return: void funcion
 */
void print_alphabet_x10(void)
{
        char c;
        int i;

        i = 0;
        while (i < 10)
        {
                c = 'a';
                while (c <= 'z')
                {
                        _putchar(c);
                        c++;
                }
                _putchar('\n');
                i++;
        }
}
