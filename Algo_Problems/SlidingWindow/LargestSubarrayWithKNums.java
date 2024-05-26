package Algo_Problems.SlidingWindow;

/*
 * Given an array, find the subarray (containing at least k numbers) which has
 * the largest sum.
 */

public class LargestSubarrayWithKNums {
    public static void main(String[] args) {
        long arr[] = { -4, -2, 1, -3 };
        int k = 2;

        solve(arr, k);
    }

    static void solve(long nums[], int k) {
        int idx = 0;
        long prevSum = 0;
        long maxSum = Integer.MIN_VALUE, curSum = 0;

        for (int i = 0; i < k; i++)
            curSum += nums[i];

        maxSum = Math.max(maxSum, curSum);

        for (int i = k; i < nums.length; i++) {
            curSum += nums[i];
            prevSum += nums[idx++];

            maxSum = Math.max(maxSum, curSum);
            if (prevSum < 0) {
                curSum -= prevSum;
                maxSum = Math.max(maxSum, curSum);
                prevSum = 0;
            }
        }

        System.out.println("Max length: " + maxSum);
    }
}
