package Algo_Problems.Recursion.Easy;

public class CheckIfStringIsPalindrome {
    public static void main(String[] args) {
        String s = "oyoyol";
        System.out.println(solve(s, 0, s.length() - 1));
    }

    static boolean solve(String str, int s, int e) {
        if (s == e) {
            return true;
        }

        if (str.charAt(s) != str.charAt(e)) {
            return false;
        }

        return solve(str, s + 1, e - 1);
    }
}
