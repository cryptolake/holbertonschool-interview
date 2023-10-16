#!/usr/bin/python3
"""Prime Game."""

def isPrime(num):
    """Check if number is prime."""
    if num <= 1:
        return False
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False
    return True

# def removeMult(prime, n_set):
#     """Remove multiple of primes from set."""
#     m_set = set()
#     for n in n_set:
#         if (n % prime != 0):
#             m_set.add(n)
#
#     return m_set
            
def getPrimes(n_set):
    """Get primes from set."""
    p_set = set()
    for n in n_set: 
        if isPrime(n):
            p_set.add(n)
    return p_set

# class Game:
#     def __init__(self, init=0, names=["Maria", "Ben"]):
#         self.turn = init
#         self.names = names
#         self.current = self.names[self.turn]
#         self.scores = {n: 0 for n in names}
#
#     def next(self):
#         if self.turn + 1 >= len(self.names):
#             self.turn = 0
#         else:
#             self.turn += 1
#         self.current = self.names[self.turn]
#         return self.names[self.turn]
#
#     def currLose(self):
#         self.scores[self.next()] += 1
#
#     def reset(self):
#         self.turn = 0
#         self.current = self.names[self.turn]
#
#     def winner(self):
#         return sorted(self.scores)[0]
    
# def isWinner(x, nums):
#     """Determine winner."""
#     game = Game()
#
#     for r in range(x):
#         n_set = set(range(1, nums[r]+1))
#         p_set = getPrimes(n_set)
#         if len(p_set) == 0:
#             game.currLose()
#         else:
#             for p in p_set:
#                 n_set = removeMult(p, n_set)
#                 game.next()
#             game.currLose()
#             game.reset()
#
#     return game.winner()

def isWinner(x, nums):
    """Determine winner."""
    scores = {"Maria": 0, "Ben": 0}

    if x < 1:
        return None

    for r in range(x):
        n_set = set(range(1, nums[r]+1))
        p_set = getPrimes(n_set)
        if len(p_set) == 0:
            scores["Ben"] += 1
        elif len(p_set) % 2 == 0: 
            scores["Ben"] += 1
        else:
            scores["Maria"] += 1
    return sorted(scores)[0]

