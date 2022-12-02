#!/usr/bin/python3
"""Rain down on africaaaa!."""


def cal_inter(walls, w1, w2):
    """Calculate intermediate walls."""
    i = w1+1
    inter = 0
    while i < w2:
        inter += walls[i]
        i += 1
    return inter


def rain(walls):
    """Rain down on africaaaa!."""
    if len(walls) == 0:
        return 0

    water = 0
    i = 0
    while i < len(walls) - 1:
        w = walls[i]
        if w > 0:
            w1 = i
            j = i + 1
            while j < len(walls):
                if walls[j] != 0:
                    w2 = j
                    if walls[w2] >= walls[w1]:
                        break
                j += 1
            inter = cal_inter(walls, w1, w2)
            if w1 == w2:
                break
            if walls[w1] >= walls[w2]:
                water += walls[w2] * (w2 - w1 - 1) - inter
            else:
                water += walls[w1] * (w2 - w1 - 1) - inter
            i += w2 - w1
        else:
            i += 1

    return water
