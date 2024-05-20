package Algo_Problems.Backtracking;

/*
 *  A knight is placed on the first block of an empty board and, 
 *  moving according to the rules of chess, must visit each 
 *  square exactly once. 
 */

public class KnightTour {
    static int board[][] = new int[8][8];
    static int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    static int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };

    public static void main(String[] args) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                board[i][j] = 0;

        solve(0, 0, 1);

        for (

                int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(board[i][j] + "        ");
            }
            System.out.println("");
        }
    }

    static boolean isValidCell(int x, int y) {
        int m = board.length;
        int n = board[0].length;

        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] >= 1) {
            return false;
        }

        return true;
    }

    static int getNPossibleMovesFromCell(int x, int y) {
        int nMoves = 0;
        for (int i = 0; i < 8; i++) {
            int posX = x + dx[i];
            int posY = y + dy[i];
            if (isValidCell(posX, posY)) {
                nMoves++;
            }
        }

        return nMoves;
    }

    static void solve(int curX, int curY, int nthMove) {
        if (!isValidCell(curX, curY)) {
            return;
        }

        board[curX][curY] = nthMove;
        int newPosX = -1, newPosY = -1;
        int minNPossibleMoves = Integer.MAX_VALUE;

        for (int i = 0; i < 8; i++) {
            int posX = curX + dx[i];
            int posY = curY + dy[i];
            if (isValidCell(posX, posY)) {
                int nMoves = getNPossibleMovesFromCell(posX, posY);
                if (minNPossibleMoves > nMoves) {
                    minNPossibleMoves = nMoves;
                    newPosX = posX;
                    newPosY = posY;
                }
            }
        }

        solve(newPosX, newPosY, nthMove + 1);
    }
}
