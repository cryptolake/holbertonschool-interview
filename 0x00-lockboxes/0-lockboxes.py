#!/usr/bin/python3
"""
Lockboxes.

You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """Solve lockboxes problem."""
    unlocked = {0: True}
    for i, box in enumerate(boxes):
        for key in box:
            if key != i and key < len(boxes):
                unlocked[key] = True
    return len(unlocked) == len(boxes)
