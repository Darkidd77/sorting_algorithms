#include "sort.h"

/**
 * selection_sort - sorts using selection algo.
 *
 * @array: array
 * @size: array size
 */

void selection_sort(int *array, size_t size)
{
	size_t x, y, z;
	int tmp;

	if (!array || !size)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (y = size - 1, z = x + 1; y > x; y--)
		{
			if (array[y] < array[z])
			{
				z = y;
			}
		}
		if (array[x] > array[z])
		{
			tmp = array[x];
			array[x] = array[z];
			array[z] = tmp;
			print_array(array, size);
		}
	}
}
