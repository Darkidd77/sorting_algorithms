#include "sort.h"

/**
 * swap - Swap two integers
 *
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 *
 * Return: void
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto - Lomuto partition scheme
 *
 * @array: Integer array
 * @size: Array size
 * @l: Low index
 * @h: High index
 *
 * Return: The final position of the pivot element
 */
size_t lomuto(int *array, size_t size, ssize_t l, ssize_t h)
{
	int x, y, pvt = array[h];

	for (x = y = l; y < h; y++)
	{
		if (array[y] < pvt)
		{
			swap(&array[y], &array[x]);
			x++;
		}
	}

	swap(&array[x], &array[h]);
	return (x);
}

/**
 * quicks - Quick sort using Lomuto scheme
 *
 * @array: Integer array
 * @size: Array size
 * @l: Low index
 * @h: High index
 *
 * Return: void
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

/**
 * quick_sort - Call to perform quick sort
 *
 * @array: Integer array
 * @size: Array size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quicks(array, size, 0, size - 1);
}
