#include "sort.h"

/**
 * bubble_sort - Function to sort an array of ints
 *
 * @array: Array with ints values
 * @size: Array size
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t x, j;
	int s;

	if (!array || size <= 1)
		return;

	x = 0;
	while (x < size)
	{
		s = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				s = 1;
			}
		}
		x++;

		if (!s)
			break;
	}
}
