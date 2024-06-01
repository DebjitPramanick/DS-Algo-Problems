package Algo_Problems.SpiralMatrix;

/*
 * Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.
 */

public class SpiralMatrix2 {
    public static void main(String[] args) {
        solve(3);
    }

    static void solve(int n) {
        int mat[][] = new int[n][n];
        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };
        int di = 0;
        boolean vis[][] = new boolean[n][n];

        int x = 0, y = 0;

        for (int i = 0; i < n * n; i++) {
            mat[x][y] = i + 1;
            vis[x][y] = true;

            int newX = x + dx[di];
            int newY = y + dy[di];

            if (newX < 0 || newX >= n || newY < 0 || newY >= n || vis[newX][newY]) {
                di = (di + 1) % 4;
                newX = x + dx[di];
                newY = y + dy[di];
            }

            x = newX;
            y = newY;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(mat[i][j] + " ");
            }
            System.out.println("");
        }
    }
}
