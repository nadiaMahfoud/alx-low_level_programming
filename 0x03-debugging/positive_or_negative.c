#include"main.h"
#include <stdlib.h>
#include <stdio.h>

/**
* positive_or_negative - If positive or nigative
*
* Return: Always 0
*/
void positive_or_negative(int n)
{
        if (n > 0)
                printf("%i is positive\n", n);
        else if (n == 0)
                printf("%i is zero\n", n);
        else
                printf("%i is negative\n", n);
}
