#!/usr/bin/python3
"""check if data is valid utf8."""


def validUTF8(data):
    """Check if data is valid utf8."""
    exp = 0
    for byte in data:
        byte &= 0b11111111
        if byte >> 4 == 0b1111:
            if exp != 0:
                return False
            exp = 3
        elif byte >> 5 == 0b111:
            if exp != 0:
                return False
            exp = 2
        elif byte >> 6 == 0b11:
            if exp != 0:
                return False
            exp = 1
        elif byte >> 7 == 0b1:
            if exp == 0:
                return False
            exp -= 1
        elif byte >> 7 == 0b0:
            if exp != 0:
                return False
    if exp > 0:
        return False
    return True
