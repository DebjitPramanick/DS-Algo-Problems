package Algo_Problems.Intervals;

import java.util.Arrays;

/*
 * Given an array intervals where intervals[i] = [li, ri] 
 * represent the interval [li, ri), remove all intervals 
 * that are covered by another interval in the list.
 * The interval [a, b) is covered by the interval [c, d) 
 * if and only if c <= a and b <= d.
 * 
 * Return the number of remaining intervals.
 */

public class RemoveCoveredIntervals {
    public static void main(String[] args) {
        int intervals[][] = { { 1, 4 }, { 3, 6 }, { 2, 8 } };
        solve(intervals);
    }

    static void solve(int intervals[][]) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int count = 1;
        int[] prev = { intervals[0][0], intervals[0][1] };

        for (int i = 1; i < n; i++) {
            int[] cur = intervals[i];
            System.out.println(cur[0] + " " + cur[1] + " -> " + prev[0] + " " + prev[1]);
            if (cur[0] >= prev[0] && cur[1] <= prev[1]) {
                continue;
            }
            prev[0] = cur[0];
            prev[1] = cur[1];
            count++;
        }

        System.out.println("Remaining intervals are: " + count);

    }
}
