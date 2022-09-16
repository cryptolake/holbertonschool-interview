#!/usr/bin/python3
"""
Minimum Operations.

In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations needed
to result in exactly n H characters in the file.

Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
Example:

n = 9

H => Copy All => Paste => HH => Paste =>HHH => Copy All
=> Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6
"""


def minOperations(n):
    """Minimum Operations."""
    r = 0
    op = 0
    i = 1
    while i < n:
        if n % i == 0:
            op += 2
            r = i
            i += r
        else:
            i += r
            op += 1
    if i == n:
        return op
    else:
        return 0
