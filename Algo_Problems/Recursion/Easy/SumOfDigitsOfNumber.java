package Algo_Problems.Recursion.Easy;

public class SumOfDigitsOfNumber {
    public static void main(String[] args) {
        System.out.println(solve(143));
    }

    static int solve(int num) {
        if (num == 0)
            return 0;

        int digit = num % 10;
        return digit + solve(num / 10);
    }
}
