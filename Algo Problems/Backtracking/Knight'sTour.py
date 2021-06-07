# Fill the chess board array number of moves in a certain box.

def solve(board, i, j, move):
    if i<0 or j<0 or i>=len(board) or j>=len(board) or board[i][j] > 0: return
    elif move == len(board) * len(board) - 1:
        board[i][j] = move
        print(board)
        board[i][j] = 0
        return

    board[i][j] = move

    solve(board, i-2, j+1, move + 1)
    solve(board, i-1, j+2, move + 1)
    solve(board, i+2, j+1, move + 1)
    solve(board, i+1, j+2, move + 1)
    solve(board, i+2, j-1, move + 1)
    solve(board, i+1, j-2, move + 1)
    solve(board, i-2, j-1, move + 1)
    solve(board, i-1, j-2, move + 1)
    board[i][j] = 0


dimension = int(input("Enter borad dimension: "))
row = int(input("Enter knight's row position: "))
col = int(input("Enter knight's column position: "))
board = [[0]*dimension for _ in range(dimension)]
solve(board, row, col, 1 )

