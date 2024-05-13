package Algo_Problems.Recursion.Medium;

/*
 * Given a 2D screen arr[][] where each arr[i][j] 
 * is an integer representing the color of that pixel, 
 * also given the location of a pixel (X, Y) and a color 
 * C, the task is to replace the color of the given pixel 
 * and all the adjacent same-colored pixels with the given 
 * color.
 */

public class FloodFillAlgo {
    static int m, n;

    public static void main(String[] args) {
        int[][] screen = {
                { 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 1, 0, 0 },
                { 1, 0, 0, 1, 1, 0, 1, 1 },
                { 1, 2, 2, 2, 2, 0, 1, 0 },
                { 1, 1, 1, 2, 2, 0, 1, 0 },
                { 1, 1, 1, 2, 2, 2, 2, 0 },
                { 1, 1, 1, 1, 1, 2, 1, 1 },
                { 1, 1, 1, 1, 1, 2, 2, 1 } };

        m = screen.length;
        n = screen[0].length;

        int x = 4, y = 4;
        int newColor = 3;
        int adjColor = screen[x][y];

        solve(screen, x, y, adjColor, newColor);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(screen[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void solve(int[][] screen, int x, int y, int adjColor, int newColor) {
        if (x < 0 || x >= m || y < 0 || y >= n || screen[x][y] != adjColor) {
            return;
        }

        screen[x][y] = newColor;
        solve(screen, x, y + 1, adjColor, newColor);
        solve(screen, x, y - 1, adjColor, newColor);
        solve(screen, x + 1, y, adjColor, newColor);
        solve(screen, x - 1, y, adjColor, newColor);
    }
}
