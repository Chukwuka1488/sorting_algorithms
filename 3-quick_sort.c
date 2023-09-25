#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: position of the pivot
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;
	int temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_sort - recursive function implementing lomuto partition scheme
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: void
 */
void lomuto_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot = lomuto_partition(array, low, high, size);

		lomuto_sort(array, low, pivot - 1, size);
		lomuto_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}
