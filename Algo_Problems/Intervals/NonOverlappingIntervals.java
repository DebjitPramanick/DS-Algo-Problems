package Algo_Problems.Intervals;

import java.util.Arrays;

/*
 * Given an array of intervals intervals where 
 * intervals[i] = [starti, endi], return the 
 * minimum number of intervals you need to remove 
 * to make the rest of the intervals non-overlapping.
 * 
 * Solution: Count only valid intervals
 */

public class NonOverlappingIntervals {
    public static void main(String[] args) {
        int intervals[][] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 } };
        solve(intervals);
    }

    static void solve(int intervals[][]) {
        int n = intervals.length;

        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

        int prevIdx = 0;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= intervals[prevIdx][1]) {
                prevIdx = i;
                count++;
            }
        }

        int ans = n - count;

        System.out.println("Remove at least: " + ans + " interval(s).");
    }
}
