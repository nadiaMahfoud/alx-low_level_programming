#include"main.h"

/**
 * _isalpha - function that check if alphabet
 * @c: the int cheker
 * Return: 1 if c is alpha and 0 if no
 */
int _isalpha(int c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return (1);
        return (0);
}
