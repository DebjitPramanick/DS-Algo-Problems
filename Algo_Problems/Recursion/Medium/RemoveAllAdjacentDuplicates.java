package Algo_Problems.Recursion.Medium;

/*
 * Given a string, recursively remove adjacent duplicate characters from the string. The output string should not have any adjacent duplicates
 */

public class RemoveAllAdjacentDuplicates {

    static char lastRemovedChar;

    public static void main(String[] args) {
        String s = "azxxzy";
        System.out.println(solve(s));
    }

    static String solve(String s) {
        if (s.length() <= 1) {
            return s;
        }

        if (s.charAt(0) == s.charAt(1)) {
            lastRemovedChar = s.charAt(0);
            while (s.length() > 1 && s.charAt(0) == s.charAt(1)) {
                s = s.substring(1);
            }
            s = s.substring(1);
            return solve(s);
        }

        String remStr = solve(s.substring(1));

        if (remStr.length() >= 1 && s.charAt(0) == remStr.charAt(0)) {
            lastRemovedChar = s.charAt(0);
            return remStr.substring(1);
        }

        if (remStr.isEmpty() && lastRemovedChar == s.charAt(0)) {
            return remStr;
        }

        return s.charAt(0) + remStr;
    }
}
