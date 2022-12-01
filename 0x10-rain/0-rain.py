#!/usr/bin/python3
"""Rain down on africaaaa!."""


def rain(walls):
    """Rain down on africaaaa!."""
    if len(walls) == 0:
        return 0

    water = 0
    for i, w in enumerate(walls[:-1]):
        if w > 0:
            w1 = i
            j = i + 1
            while j < len(walls):
                if walls[j] > 0:
                    w2 = j
                    break
                j += 1
            if w1 == w2:
                break
            if walls[w1] >= walls[w2]:
                water += walls[w2] * (w2 - w1 - 1)
            else:
                water += walls[w1] * (w2 - w1 - 1)

    return water
