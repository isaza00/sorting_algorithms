#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {1, 2, 3, 4, 6, 5, 7, 8, 9};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("-------------\n");

	quick_sort(array, n);
	return (0);
}
