#!/usr/bin/python3
"""Find island Perimeter."""


def is_valid(x, y, grid):
    """Test if x, y coordinate are valid."""
    line, col = len(grid), len(grid[0])

    if x > line or y > col or x < 0 or y < 0:
        return False
    return True


def island_perimeter(grid):
    """Find island Perimeter."""
    per = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                per += 4
                if is_valid(i+1, j, grid) and grid[i+1][j] == 1:
                    per -= 1
                if is_valid(i, j+1, grid) and grid[i][j+1] == 1:
                    per -= 1
                if is_valid(i-1, j, grid) and grid[i-1][j] == 1:
                    per -= 1
                if is_valid(i, j-1, grid) and grid[i][j-1] == 1:
                    per -= 1
    return per
