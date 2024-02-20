#include "sort.h"

/**
 * bubble_sort - fun. to sort an array of ints
 * bubble sort algorithm
 *
 * @array: array with ints value
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t x, j;

	if (!array || !size)
		return;

	x = 0;
	while (x < size)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		x++;
	}
}
