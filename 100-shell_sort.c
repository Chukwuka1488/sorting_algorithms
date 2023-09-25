#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 *              Shell sort algorithm, using the Knuth sequence
 * @array: an array of integers
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Compute initial gap using Knuth sequence */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}

		/* Print array each time we decrease the interval */
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
