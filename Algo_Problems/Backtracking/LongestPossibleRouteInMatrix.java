package Algo_Problems.Backtracking;

/*
 * Given an M x N matrix, with a few hurdles arbitrarily placed, 
 * calculate the length of the longest possible route possible 
 * from source to a destination within the matrix. We are allowed 
 * to move to only adjacent cells which are not hurdles. The route 
 * cannot contain any diagonal moves and a location once visited in 
 * a particular path cannot be visited again.
 */

public class LongestPossibleRouteInMatrix {
    static int rowNum[] = { -1, 0, 0, 1 };
    static int colNum[] = { 0, -1, 1, 0 };
    static int ans = Integer.MIN_VALUE;
    static int destX = 0;
    static int destY = 0;

    public static void main(String[] args) {
        int mat[][] = {
                { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
        };
        boolean vis[][] = new boolean[3][10];
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                vis[i][j] = false;
            }
        }

        destX = 1;
        destY = 7;

        solve(mat, vis, 0, 0, 0);
        System.out.println("Distance: " + ans);
    }

    static boolean isSafeCell(int x, int y, int mat[][]) {
        int m = mat.length;
        int n = mat[0].length;

        if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] == 0) {
            return false;
        }
        return true;
    }

    static void solve(int mat[][], boolean[][] vis, int curX, int curY, int dist) {
        if (curX == destX && curY == destY) {
            ans = Math.max(ans, dist);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = curX + rowNum[i];
            int newY = curY + colNum[i];
            if (!isSafeCell(newX, newY, mat)) {
                continue;
            }
            if (!vis[newX][newY]) {
                vis[newX][newY] = true;
                solve(mat, vis, newX, newY, dist + 1);
                vis[newX][newY] = false;
            }

        }
    }
}
