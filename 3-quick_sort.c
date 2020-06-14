#include "sort.h"
#include <stdio.h>
/**
 * partition - separate the array into to partitions
 * @array: doble pointer to node list
 * @first: start of sublist
 * @end: end of sublist
 * @size: size of the array
 * Return: prints array each time it swaps
 */
size_t partition(int *array, size_t first, size_t end, size_t size)
{
	size_t pivot_index = first, i = first;
	int pivot = array[end], temp;

	while (i < end)
	{
		if (array[i] < pivot)
		{
			if (pivot_index != i)
			{
				temp = array[i];
				array[i] = array[pivot_index];
				array[pivot_index] = temp;
				print_array(array, size);
			}
			pivot_index += 1;
		}
		i += 1;
	}
	if (pivot_index != end)
	{
		temp = array[pivot_index];
		array[pivot_index] = pivot;
		array[end] = temp;
		print_array(array, size);
	}
	return (pivot_index);
}
/**
 * sort - sort recursively both sublists
 * @array: pointer to aaray
 * @first: start of sublist
 * @end: end of sublist
 * @size: size of the array
 * Return: prints array each time it swaps
 */
void sort(int *array, long long int first, long long int end, size_t size)
{
	long long int pivot_index;

	if (first < end)
	{
		pivot_index = partition(array, first, end, size);
		sort(array, first, pivot_index - 1, size);
		sort(array, pivot_index + 1, end, size);
	}
}
/**
 * quick_sort - orders array with quick sort algo
 * @array: pointer to array
 * @size: size of the array
 * Return: prints array each time it swaps
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
