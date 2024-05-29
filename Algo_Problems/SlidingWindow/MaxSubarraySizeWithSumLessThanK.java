package Algo_Problems.SlidingWindow;

/*
 * Given an array of n positive integers and a positive integer k, 
 * the task is to find the maximum subarray size such that all 
 * subarrays of that size have the sum of elements less than or 
 * equals to k.
 */

public class MaxSubarraySizeWithSumLessThanK {
    public static void main(String[] args) {
        int nums[] = { 1, 2, 10, 4 };
        int k = 8;
        solve(nums, k);
    }

    static void solve(int nums[], int k) {
        int start = 0;
        int curSum = 0;
        int subarraySize = 0;
        boolean notPossible = false;

        for (int end = 0; end < nums.length; end++) {
            curSum += nums[end];
            while (curSum > k) {
                curSum -= nums[start++];
                subarraySize = Math.max(end - start + 1, subarraySize);

                if (curSum == 0) {
                    notPossible = true;
                    break;
                }
            }
            if (notPossible) {
                subarraySize = -1;
                break;
            }
        }

        System.out.println(subarraySize);
    }
}
