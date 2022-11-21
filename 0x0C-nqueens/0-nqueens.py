#!/usr/bin/python3
"""N queens classical problem."""
import sys


def get_sol(board, n):
    """Get solution from board."""
    sols = []
    for x in range(n):
        for y in range(n):
            if board[x][y]:
                sols.append([x, y])
    return sols


def isvalid(board, pos, n):
    """Check if position is valid on the board."""
    for i in range(0, n):
        if board[pos[0]][i]:
            return False
        if board[i][pos[1]]:
            return False
        if pos[0]+i < n and pos[1]+i < n:
            if board[pos[0]+i][pos[1]+i]:
                return False
        if pos[0]-i >= 0 and pos[1]-i >= 0:
            if board[pos[0]-i][pos[1]-i]:
                return False
        if pos[0]+i < n and pos[1]-i >= 0:
            if board[pos[0]+i][pos[1]-i]:
                return False
        if pos[0]-i >= 0 and pos[1]+i < n:
            if board[pos[0]-i][pos[1]+i]:
                return False
    return True


def solvenqueen(board, cols, col, n):
    """Solve n queen using backtracking."""
    if col == n:
        return True
    for i in range(n):
        if isvalid(board, (i, cols[col]), n):
            board[i][cols[col]] = True
            if solvenqueen(board, cols, col+1,  n):
                return True
            board[i][cols[col]] = False
    return False


def main():
    """Solve n queen using backtracking."""
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)

    if N < 4:
        print('N must be at least 4')
        exit(1)

    sols = []
    for i in range(N):
        board = [[False for _ in range(N)] for _ in range(N)]
        cols = list(range(N))
        cols.remove(i)
        cols.insert(0, i)
        if solvenqueen(board, cols, 0, N):
            sol = get_sol(board, N)
            if sol not in sols:
                sols.append(sol)
                print(sol)


main()
