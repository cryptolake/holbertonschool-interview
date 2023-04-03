#!/usr/bin/python3
"""Determine the fewest number of coins needed to meet a given amount total."""

# def rec_change(coins, total, i, c, min_c):
#     if i == len(coins) and total != 0:
#         return -1
#     if total == 0:
#         return c
    
#     for j in range(len(coins)):

        

#     return min_c


def makeChange(coins, total):
    """Determine the fewest number of coins."""
    # scoins = sorted(coins, reverse=True)
    # return rec_change(scoins, total, 0, 0, -1)
    i = 0
    for coin in coins:
        j = total // coin
        total -= j * coin
        i += j
        if total <= 0:
            break

    if total != 0:
        i = -1

    return i
