package Algo_Problems.Backtracking.ChessType;

public class RatMaze {
    public static void main(String[] args) {
        int n = 3;
        int maze[][] = { { 1, 0, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
        solve(maze, 0, 0, "");
    }

    static void solve(int maze[][], int x, int y, String ans) {

        int n = maze.length;

        if (x == n - 1 && y == n - 1) {
            System.out.println("Path is: " + ans);
            return;
        }

        int dx[] = { 0, 1, 0, 0 };
        int dy[] = { 1, 0, -1, -1 };
        String moves[] = { "R", "D", "L", "U" };

        for (int i = 0; i < 4; i++) {
            if (isSafe(x + dx[i], y + dy[i], maze)) {
                maze[x][y] = 0;
                String orig = ans;
                ans += moves[i] + "->";
                solve(maze, x + dx[i], y + dy[i], ans);
                maze[x][y] = 1;
                ans = orig;
            }
        }
    }

    static boolean isSafe(int x, int y, int maze[][]) {
        int n = maze.length;

        if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] != 0) {
            return true;
        }

        return false;
    }
}
