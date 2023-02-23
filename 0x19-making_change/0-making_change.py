#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed to meet a given amount total.
"""

def makeChange(coins, total):
    """Determine the fewest number of coins."""
    i = 0
    for coin in sorted(coins, reverse=True):
        j = total // coin
        total -= j * coin 
        i += j
        if total <= 0:
            break

    if total != 0:
        i = -1

    return i
