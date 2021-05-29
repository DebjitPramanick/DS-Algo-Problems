def isSafe(board, i, j, n):

    for row in range(i):
        if board[row][j] == 1: return False
    
    x = i
    y = j

    while x>=0 and y>=0:
        if board[x][y] == 1: return False
        x, y = x-1, y -1

    x = i
    y = j

    while x>=0 and y<n:
        if board[x][y] == 1: return False
        x, y = x-1, y+1

    return True

count = 0

def solve(board, index, n):
    global count
    if index==n:
        count += 1
        print("It is a solution: ")
        for i in range(n):
            for j in range(n):
                if board[i][j] == 1: print('Q ', end="")
                else: print("_ ", end="")
            print("\n")
        return False
    
    for j in range(n):
        if isSafe(board, index, j, n):
            board[index][j] = 1
            nextQ = solve(board, index+1, n)
            if nextQ: return True
            else: board[index][j] = 0

    return False


dimension = int(input("Enter borad dimension: "))

board = [[0]*dimension for _ in range(dimension)]

solve(board, 0, dimension )
print("Number of solutions are: ", count)