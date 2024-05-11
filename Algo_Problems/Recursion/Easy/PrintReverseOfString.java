package Algo_Problems.Recursion.Easy;

public class PrintReverseOfString {
    public static void main(String[] args) {
        String s = "Reverse";
        String ans = solve(s, s.length());
        System.out.println(ans);
    }

    static String solve(String s, int n) {
        if (n == 1) {
            return s.substring(0, n);
        }
        return s.substring(n - 1, n) + solve(s, n - 1);

    }
}
