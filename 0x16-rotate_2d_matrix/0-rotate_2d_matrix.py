#!/usr/bin/python3
"""Rotate 2D matrix python."""


def rotate_2d_matrix(matrix):
    """Rotate 2D matrix python."""
    n = len(matrix)
    mtx = []
    for i in range(n):
        mtx.append([])
        for j in range(n-1, -1, -1):
            mtx[i].append(matrix[j][i])
    for i in range(n):
        matrix[i] = mtx[i]
