package Algo_Problems.Intervals;

import java.util.ArrayList;
import java.util.List;

/*
 * You are given an array of non-overlapping intervals intervals 
 * where intervals[i] = [starti, endi] represent the start and 
 * the end of the ith interval and intervals is sorted in ascending 
 * order by starti. You are also given an interval 
 * newInterval = [start, end] that represents the start and end of 
 * another interval.
 * 
 * Insert newInterval into intervals such that intervals is still 
 * sorted in ascending order by starti and intervals still does not 
 * have any overlapping intervals (merge overlapping intervals if necessary).
 * 
 * Return intervals after the insertion.
 * Note that you don't need to modify intervals in-place. You can make a new array and return it.
 */

public class InsertIntervals {
    public static void main(String[] args) {
        int intervals[][] = { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } };
        int newInterval[] = { 4, 8 };
        solve(intervals, newInterval);
    }

    static void solve(int intervals[][], int newInterval[]) {
        List<int[]> result = new ArrayList<>();

        for (int[] inv : intervals) {
            if (inv[1] < newInterval[0]) {
                result.add(inv);
            } else if (inv[0] > newInterval[1]) {
                result.add(newInterval);
                newInterval = inv;
            } else {
                newInterval[0] = Math.min(inv[0], newInterval[0]);
                newInterval[1] = Math.max(inv[1], newInterval[1]);
            }
        }
        result.add(newInterval);

        int ans[][] = result.toArray(new int[result.size()][]);

        for (int i = 0; i < ans.length; i++) {
            System.out.print("{" + ans[i][0] + "," + ans[i][1] + "}");
        }
        System.out.println("");
    }
}

/*
 * 1,2
 * --
 * --
 * 3,8
 * 12,16
 */