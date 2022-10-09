#include "search_algos.h"

/**
* print_array - Print an array according to the start and end pointer
*
* @array: The array to search in
* @start: Pointer to the first index of the current subarray
* @end: Pointer to the last index of the current subarray
*
* Return: Anything, cause void function
*/
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	if (!array)
		return;
	printf("Searching in array:");
	for (i = start; i < end; i++)
		printf(" %d,", array[i]);
	printf(" %d\n", array[i]);
}

/**
* binary_search_rec - Search algo using binary search time complexity
*
* @array: The array to search in
* @start: Pointer to the first index of the current subarray
* @end: Pointer to the last index of the current subarray
* @value: The value to find
*
* Return: The index of the founded value, -1 if any issues
*/
int binary_search_rec(int *array, size_t start, size_t end, int value)
{
	int middle;

	if (start > end)
		return (-1);
	print_array(array, start, end);
	middle = (start + end) / 2;
	if (value == array[middle])
		return (middle);
	if (value < array[middle])
		return (binary_search_rec(array, start, middle - 1, value));
	return (binary_search_rec(array, middle + 1, end, value));
}

/**
* exponential_search - Search a value using the exponential search
*
* @array: The array to search in
* @size: The size of the array
* @value: The value to find
*
* Return: The index of the founded value, -1 if any issues
*/
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t end;

	if (!array)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	bound /= 2;
	end = bound * 2 < size - 1 ? bound * 2 : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", bound, end);

	return (binary_search_rec(array, bound, end, value));
}
