#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, and then in uppercase.
 *
 * Return: Always 0.
 */
int main()
{
    char ch;
    int i;
    for(i=0;i<=25; i++){
    ch = 'a' + i;
    putchar(ch);
    }
    for(i=0;i<=25; i++){
    ch = 'A' + i;
    putchar(ch);
    }
    putchar('\n');
    return (0);
}

