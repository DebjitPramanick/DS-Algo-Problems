package Algo_Problems.SpiralMatrix;

// Print matrix in spiral form

public class SpiralMatrix {
    public static void main(String[] args) {
        int mat[][] = {
                { 1, 2, 3, 4 },
                { 5, 6, 7, 8 },
                { 9, 10, 11, 12 },
                { 13, 14, 15, 16 }
        };
        solve(mat);
    }

    static void solve(int mat[][]) {
        int m = mat.length;
        int n = mat[0].length;

        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };
        int di = 0;
        boolean vis[][] = new boolean[m][n];

        int x = 0, y = 0;

        for (int i = 0; i < m * n; i++) {
            System.out.println(mat[x][y]);
            vis[x][y] = true;

            int newX = x + dx[di];
            int newY = y + dy[di];

            if (newX < 0 || newX >= m || newY < 0 || newY >= n || vis[newX][newY]) {
                di = (di + 1) % 4;
                newX = x + dx[di];
                newY = y + dy[di];
            }

            x = newX;
            y = newY;
        }
    }
}
