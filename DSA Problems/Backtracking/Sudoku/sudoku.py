def isSafe(board, x, y, val):
    for m in range(len(board[0])):
        if val == board[m][y]: return False

    for n in range(len(board[0])):
        if val == board[x][n]: return False

    smi = (x//3) * 3
    smj = (y//3) * 3

    for m in range(3):
        for n in range(3):
            if board[smi+m][smj+n] == val:
                return False
    
    return True



def solve(board, i, j):

    if i == len(board):
        print(board)
        return 
    
    ni = 0
    nj = 0
    if j == len(board[0])-1: 
        ni = i+1
        nj = 0
    else: 
        ni = i
        nj = j+1

    if board[i][j] != 0:
        solve(board, ni, nj)
    else:
        for po in range(1,10):
            if isSafe(board, i, j, po):
                board[i][j] = po
                solve(board, ni, nj)
                board[i][j] = 0


sudoku = [[0,0,1,0,3,9,0,0,0],
          [0,7,2,0,0,0,0,9,0],
          [0,0,0,0,0,6,0,8,0],
          [0,5,0,0,0,0,0,0,0],
          [0,0,0,2,0,0,0,5,0],
          [3,0,0,0,0,0,0,0,0],
          [0,0,0,0,1,0,3,0,0],
          [0,4,0,0,0,0,0,0,0],
          [9,0,0,0,4,0,0,0,5]
        ]


solve(sudoku, 0, 0)