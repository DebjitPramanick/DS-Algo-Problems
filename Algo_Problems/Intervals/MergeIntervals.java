package Algo_Problems.Intervals;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/*
 * Given a set of time intervals in any order, 
 * our task is to merge all overlapping intervals 
 * into one and output the result which should have 
 * only mutually exclusive intervals.
 */

public class MergeIntervals {
    public static void main(String[] args) {
        int intervals[][] = { { 1, 3 }, { 2, 4 }, { 6, 8 }, { 9, 10 } };
        solve(intervals);
    }

    static Comparator<int[]> comparator() { // Custom comparator
        return new Comparator<int[]>() {
            @Override
            public int compare(int entry1[], int entry2[]) {
                return Integer.compare(entry1[0], entry2[0]);
            }
        };
    }

    static void solve(int intervals[][]) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> merged = new ArrayList<>();
        int[] prev = intervals[0];

        for (int i = 1; i < intervals.length; i++) {
            int[] interval = intervals[i];
            if (interval[0] <= prev[1]) {
                prev[1] = Math.max(prev[1], interval[1]);
            } else {
                merged.add(prev);
                prev = interval;
            }
        }

        merged.add(prev);

        int ans[][] = merged.toArray(new int[merged.size()][]);

        for (int i = 0; i < ans.length; i++) {
            System.out.print("{" + ans[i][0] + "," + ans[i][1] + "}");
        }
        System.out.println("");
    }
}
