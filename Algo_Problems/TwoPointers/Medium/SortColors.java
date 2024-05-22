package Algo_Problems.TwoPointers.Medium;

/*
 * Given an array colors with n objects colored red, white, or blue, 
 * sort them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, 
 * white, and blue, respectively.
 */

public class SortColors {
    public static void main(String[] args) {
        int colors[] = { 2, 0, 2, 1, 1, 0 };
        solveOnePass(colors);
    }

    static void solve(int colors[]) {
        if (colors.length <= 1) {
            return;
        }
        int i = 0, j = i + 1;

        while (j < colors.length) {
            if (colors[i] != 0) {
                if (colors[j] != 0) {
                    j++;
                } else {
                    int temp = colors[i];
                    colors[i] = colors[j];
                    colors[j] = temp;
                    i++;
                    j++;
                }
            } else {
                i++;
            }
        }

        j = i + 1;

        while (j < colors.length) {
            if (colors[i] != 1) {
                if (colors[j] != 1) {
                    j++;
                } else {
                    int temp = colors[i];
                    colors[i] = colors[j];
                    colors[j] = temp;
                    i++;
                    j++;
                }
            } else {
                i++;
            }
        }

        for (int k = 0; k < colors.length; k++) {
            System.out.print(colors[k] + " ");
        }
    }

    static void solveOnePass(int colors[]) {
        if (colors.length <= 1) {
            return;
        }
        int start = 0, end = colors.length - 1;
        int cur = 0;

        while (cur < colors.length && start < end) {
            if (colors[cur] == 0 && cur > start) {
                int temp = colors[start];
                colors[start] = colors[cur];
                colors[cur] = temp;
                start++;
            } else if (colors[cur] == 2 && cur < end) {
                int temp = colors[end];
                colors[end] = colors[cur];
                colors[cur] = temp;
                end--;
            } else {
                cur++;
            }
        }

        for (int k = 0; k < colors.length; k++) {
            System.out.print(colors[k] + " ");
        }
    }
}
