package Algo_Problems.Intervals;

import java.util.ArrayList;
import java.util.List;

/*
 * You are given two lists of closed intervals, firstList and secondList,
 *  where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
 * Each list of intervals is pairwise disjoint and in sorted order.
 * Return the intersection of these two interval lists.
 * 
 * A closed interval [a, b] (with a <= b) denotes the set of real numbers 
 * x with a <= x <= b.
 * The intersection of two closed intervals is a set of real numbers that 
 * are either empty or represented as a closed interval. For example, the 
 * intersection of [1, 3] and [2, 4] is [2, 3].
 */

public class IntervalListIntersections {
    public static void main(String[] args) {
        int first[][] = { { 0, 2 }, { 5, 10 }, { 13, 23 }, { 24, 25 } };
        int second[][] = { { 1, 5 }, { 8, 12 }, { 15, 24 }, { 25, 26 } };

        solve(first, second);
    }

    static void solve(int first[][], int second[][]) {
        int i = 0, j = 0;
        int m = first.length, n = second.length;

        List<int[]> intersections = new ArrayList();

        while (i < m && j < n) {
            int[] fc = first[i];
            int[] sc = second[j];
            int[] nc = new int[2];

            if (fc[0] <= sc[1] && fc[1] >= sc[0]) {
                nc[0] = Math.max(fc[0], sc[0]);
                nc[1] = Math.min(fc[1], sc[1]);
                intersections.add(nc);
            }

            if (fc[1] < sc[1])
                i++;
            else
                j++;
        }

        int[][] ans = intersections.toArray(new int[intersections.size()][]);

        for (int[] inv : ans) {
            System.out.print("{" + inv[0] + "," + inv[1] + "}");
        }
    }
}
