package Algo_Problems.Kadane;

/*
 * Given an array arr[] of size N. The task is to find the sum of 
 * the contiguous subarray within a arr[] with the largest sum. 
 */

public class LongestSumContiguousSubarray {
    public static void main(String[] args) {
        int nums[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
        solve(nums);
    }

    static void solve(int nums[]) {
        int maxSoFar = Integer.MIN_VALUE;
        int maxEndingHere = 0;

        for (int i = 0; i < nums.length; i++) {
            maxEndingHere += nums[i];
            if (maxSoFar < maxEndingHere) {
                maxSoFar = maxEndingHere;
            }
            if (maxEndingHere < 0) {
                maxEndingHere = 0;
            }
        }

        System.out.println("Max sum: " + maxSoFar);
    }
}
