package Algo_Problems.PrefixSum;

/*
 * Given an array arr[] of size N. Given Q queries 
 * and in each query given L and R, Print the sum 
 * of array elements from index L to R.
 */

public class SumOfArrayBetweenIndexLAndR {
    public static void main(String[] args) {
        int nums[] = { 10, 4, 16, 20, 40, 30, 15, 35, 75, 5 };
        solve(nums, 3, 7);
    }

    static void solve(int nums[], int L, int R) {
        int n = nums.length;
        int prefixSum[] = new int[n];

        prefixSum[0] = nums[0];

        for (int i = 1; i <= R; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }

        System.out.println(prefixSum[R] - prefixSum[L - 1]);
    }
}
