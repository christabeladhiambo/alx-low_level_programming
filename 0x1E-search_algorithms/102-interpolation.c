#include "search_algos.h"

/**
* interpolation_search_rec - Search a value using the interpolation search
*                   algo.
*
* @array: The array to search in
* @value: The value to find
* @start: Pointer to the first index of the current subarray
* @end: Pointer to the last index of the current subarray
*
* Return: The index of the founded value, -1 if any issues
*/
int interpolation_search_rec(int *array, int value, size_t start, size_t end)
{
	size_t middle;

	if (start > end)
		return (-1);

	middle = start + (((double)(end - start) / (array[end] - array[start]))
				* (value - array[start]));
	if (middle > end)
	{
		printf("Value checked array[%ld] is out of range\n", middle);
		return (-1);
	}
	printf("Value checked array[%ld] = [%d]\n", middle, array[middle]);
	if (array[middle] == value)
		return (middle);
	if (array[middle] < value)
		return (interpolation_search_rec(array, value, middle + 1, end));
	return (interpolation_search_rec(array, value, start, middle - 1));
}

/**
* interpolation_search - Search a value using the interpolation search
*                   algo.
*
* @array: The array to search in
* @size: The size of the array
* @value: The value to find
*
* Return: The index of the founded value, -1 if any issues
*/
int interpolation_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (interpolation_search_rec(array, value, 0, size - 1));
}
