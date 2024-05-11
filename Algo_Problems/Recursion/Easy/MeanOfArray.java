package Algo_Problems.Recursion.Easy;

public class MeanOfArray {
    public static void main(String[] args) {
        int arr[] = { 1, 4, 7, 9, 10, 2, 3 };
        int ans = solve(arr, arr.length);
        System.out.println(ans);

    }

    static int solve(int arr[], int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return arr[n - 1];
        }

        return (solve(arr, n - 1) * (n - 1) + arr[n - 1]) / n;
    }
}
