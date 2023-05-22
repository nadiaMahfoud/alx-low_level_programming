#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Prints the information of a struct dog
 * @d: Pointer to the struct dog to print
 *
 * Description: This function prints the details of a dog structure,
 *		including its name, age, and owner.
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", (d->name) ? d->name : "(nil)");
		printf("Age: %f\n", (d->age) ? d->age : 0);
		printf("Owner: %s\n", (d->owner) ? d->owner : "(nil)");
	}
}
