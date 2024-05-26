package Algo_Problems.SlidingWindow;

/*
 * Given a string s, find the length of the longest substring 
 * without repeating characters.
 */

public class LongestSubstringWithoutRepeatingChars {
    public static void main(String[] args) {
        String s = "ABCDEFGABEF";
        solve(s);
    }

    static void solve(String s) {
        boolean visited[] = new boolean[256];
        int ans = 0;
        int start = 0, end = 0;
        while (end < s.length()) {
            if (!visited[s.charAt(end)])
                visited[s.charAt(end++)] = true;
            else {
                ans = Math.max(ans, end - start);
                visited[s.charAt(start++)] = false;
            }
        }
        ans = Math.max(ans, end - start);
        System.out.println(ans);
    }
}
