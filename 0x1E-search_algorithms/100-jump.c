#include "search_algos.h"

/**
* linear_search_jump - Search algo in linear time complexity
*
* @array: The array to search in
* @size: The size of the array
* @value: The value to find
* @min: Pointer to the first index of the current subarray
* @max: Pointer to the last index of the current subarray
*
* Return: The index of the founded value, -1 if any issues
*/
int linear_search_jump(int *array, size_t size, int value,
	size_t min, size_t max)
{
	size_t i;

	if (!array)
		return (-1);
	for (i = min; i < size && i <= max; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}

/**
* jump_search - Searching algo using JumpSearch.
*
* @array: The array to search in
* @size: The size of the array
* @value: The value to find
*
* Return: The index of the founded value, -1 if any issues
*/
int jump_search(int *array, size_t size, int value)
{
	size_t minim, middle;

	if (!array)
		return (-1);

	minim = 0;
	middle = sqrt(size);
	printf("Value checked array[%ld] = [%d]\n", minim, array[minim]);
	while (middle < size && array[middle] < value)
	{
		minim = middle;
		middle += sqrt(size);
		printf("Value checked array[%ld] = [%d]\n", minim, array[minim]);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", minim, middle);
	return (linear_search_jump(array, size, value, minim, middle));
}
