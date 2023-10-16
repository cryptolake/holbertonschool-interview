#!/usr/bin/python3
"""Prime Game."""


primeTable = {0: False, 1: False}


def isPrime(num):
    """Check if number is prime."""
    if num in primeTable:
        return primeTable[num]
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            primeTable[num] = False
            return False
    primeTable[num] = True
    return True


def getPrimes(n_set):
    """Get number of primes from set."""
    n_p = 0
    for n in n_set:
        if isPrime(n):
            n_p += 1
    return n_p


def isWinner(x, nums):
    """Determine winner."""
    scores = {"Maria": 0, "Ben": 0}
    numPrime = {2: 1, 3: 2}

    if x < 1:
        return None

    for r in range(x):
        if nums[r] in numPrime:
            n_p = numPrime[nums[r]]
        else:
            n_set = set(range(1, nums[r]+1))
            n_p = getPrimes(n_set)
            numPrime[nums[r]] = n_p
        if n_p == 0:
            scores["Ben"] += 1
        elif n_p % 2 == 0:
            scores["Ben"] += 1
        else:
            scores["Maria"] += 1
    return sorted(scores, key=lambda x: scores[x])[1]
