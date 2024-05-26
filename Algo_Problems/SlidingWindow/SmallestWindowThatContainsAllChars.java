package Algo_Problems.SlidingWindow;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
 * Given a string, find the smallest window length with 
 * all distinct characters of the given string. 
 * For eg. str = “aabcbcdbca”, then the result would be 4 
 * as of the smallest window will be “dbca” .
 */

public class SmallestWindowThatContainsAllChars {
    public static void main(String[] args) {
        String str = "aabcbcdbcjcabd";
        solve(str);
    }

    static void solve(String str) {
        boolean visited[] = new boolean[256];
        int nDistinctChars = 0;

        Arrays.fill(visited, false);

        for (int i = 0; i < str.length(); i++) {
            if (!visited[str.charAt(i)]) {
                visited[str.charAt(i)] = true;
                nDistinctChars++;
            }
        }

        int s = 0, si = -1;
        int minLen = Integer.MAX_VALUE;
        int currCount[] = new int[256];
        int nCharsIncluded = 0;

        for (int j = 0; j < str.length(); j++) {
            currCount[str.charAt(j)]++;
            if (currCount[str.charAt(j)] == 1)
                nCharsIncluded++;

            if (nCharsIncluded == nDistinctChars) {

                while (currCount[str.charAt(s)] > 1) {
                    currCount[str.charAt(s)]--;
                    s++;
                }

                // Update window size
                int lenWindow = j - s + 1;
                if (minLen > lenWindow) {
                    minLen = lenWindow;
                    si = s;
                }
            }
        }

        System.out.println(minLen + " " + str.substring(si, si + minLen));
    }
}
