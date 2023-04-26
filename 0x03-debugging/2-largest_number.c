#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
        int largest;

        if (a > b && a > c)
        {
                largest = a;
        }
        else if (b > a && b > c)
        {
                largest = b;
        }
        else if (c > a && c > b)
        {
                largest = b;
        }
        else if (a == b)
        {
                if (a > c)
                        largest = a;
                else
                        largest = c;
        }
	
                                                                                         
        else if (b == c)
        {
                if (b > a)
                        largest = b;
                else
                        largest = a;
        }

        return (largest);
}
