#!/usr/bin/python3
"""Pascal Triangle."""


def pascal_triangle(n):
    """Construct Pascal Triangle with n levels."""
    if n <= 0:
        return []
    triangle = []
    for i in range(n):
        triangle.append([])
        for j in range(i+1):
            if j == 0 or j == i:
                triangle[i].append(1)
            else:
                triangle[i].append(triangle[i-1][j] + triangle[i-1][j-1])

    return triangle
