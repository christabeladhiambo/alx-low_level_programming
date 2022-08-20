#!/usr/bin/python3
"""
Task 5
Island perimeter
"""


def island_perimeter(grid):
    """
    Determine the perimeter of a island
    Args:
        grid: 2D array that represente the ocean with the island
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j]:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1]:
                    perimeter -= 2
    return perimeter
