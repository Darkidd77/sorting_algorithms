#include "sort.h"

/**
 * swap - swap - swap two int
 *
 * @array: the int array
 * @size: array size
 * @x: 1st value address
 * @y: 2nd value address
 *
 * Return: void
 */
void swap(int *array, size_t size, int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;

}


/**
 * lomuto - array partitions
 *
 * @array: int array
 * @size: array size
 * @l: low index
 * @h: high index
 *
 * Return: void
 */
size_t lomuto(int *array, size_t size, ssize_t l, ssize_t h)
{
	int x, y, pv = array[h];

	for (x = y = l; y < h; y++)
	{
		if (array[y] < pv)
			swap(array, size, &array[y], &array[x++]);
		swap(array, size, &array[x], &array[h]);

		return (x);
	}
}



/**
 * quick_sort - fun. call
 *
 * @array: int array
 * @size: array size
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicks(array, size, 0, size - 1);
}


/**
 * quicks - quick sort Lomuto scheme
 *
 * @array: int array
 * @size: array size
 * @l: low index
 * @h: high index
 *
 */
void quicks(int *array, size_t size, ssize_t l, ssize_t h)
{
	if (l < h)
	{
		size_t q = lomuto(array, size, l, h);

		quicks(array, size, l, q - 1);
		quicks(array, size, q + 1, h);
	}
}
