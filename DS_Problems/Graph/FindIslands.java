package DS_Problems.Graph;

/**
 * FindIslands
 * Flood Fill Algo Example
 */
public class FindIslands {
    static int[][] input = {
            { 1, 1, 0, 0, 0 },
            { 0, 1, 0, 0, 1 },
            { 1, 0, 0, 1, 1 },
            { 0, 0, 0, 0, 0 },
            { 1, 0, 1, 0, 1 }
    };

    public static void main(String[] args) {
        solve();
    }

    static void solve() {
        int m = input.length;
        int n = input[0].length;
        boolean[][] vis = new boolean[m][n];
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (input[i][j] != 0 && !vis[i][j]) {
                    rec(vis, i, j);
                    count++;
                }
            }
        }
        System.out.println(count + " islands are there.");
    }

    static void rec(boolean[][] vis, int x, int y) {
        int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

        for (int i = 0; i < dx.length; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isSafe(vis, newX, newY)) {
                vis[newX][newY] = true;
                rec(vis, newX, newY);
            }
        }
    }

    static boolean isSafe(boolean[][] vis, int x, int y) {
        int m = input.length;
        int n = input[0].length;
        if (x >= 0 && x < m && y >= 0 && y < n && input[x][y] != 0 && !vis[x][y]) {
            return true;
        }

        return false;
    }
}