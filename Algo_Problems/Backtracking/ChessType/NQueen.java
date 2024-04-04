package Algo_Problems.Backtracking.ChessType;

public class NQueen {
    public static void main(String[] args) {
        int board[][] = new int[4][4];
        solve(board, 0);
    }

    static void solve(int board[][], int row) {
        int n = board.length;

        if (row == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1) {
                        System.out.print(" Q ");
                    } else {
                        System.out.print(" _ ");
                    }
                }
                System.out.println("");
            }
            System.out.println("");
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 1;
                solve(board, row + 1);
                board[row][col] = 0;
            }
        }
    }

    static boolean isSafe(int x, int y, int board[][]) {
        int n = board.length;
        for (int i = 0; i < n; i++) {
            if (board[x][i] == 1)
                return false;
            if (board[i][y] == 1)
                return false;
        }

        int i = x, j = y;

        while (i >= 0 && j < n) {
            if (board[i][j] == 1) {
                return false;
            }
            i--;
            j++;
        }
        i = x;
        j = y;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 1) {
                return false;
            }
            i--;
            j--;
        }

        return true;
    }
}
