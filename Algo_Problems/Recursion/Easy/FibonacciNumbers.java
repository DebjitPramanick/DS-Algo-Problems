package Algo_Problems.Recursion.Easy;

public class FibonacciNumbers {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            System.out.println(solve(i));
        }
    }

    static int solve(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        return solve(n - 2) + solve(n - 1);
    }
}
