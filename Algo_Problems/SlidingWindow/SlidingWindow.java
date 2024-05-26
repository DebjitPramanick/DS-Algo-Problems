package Algo_Problems.SlidingWindow;

/*
 * Sliding Window Technique is a method used to efficiently solve 
 * problems that involve defining a window or range in the input 
 * data (arrays or strings) and then moving that window across the 
 * data to perform some operation within the window. This technique 
 * is commonly used in algorithms like finding subarrays with a 
 * specific sum, finding the longest substring with unique characters, 
 * or solving problems that require a fixed-size window to process 
 * elements efficiently.
 * 
 * Problem:
 * Given an array of integers of size ‘n’, Our aim is to calculate the 
 * maximum sum of ‘k’ consecutive elements in the array.
 */

public class SlidingWindow {
    public static void main(String[] args) {
        int nums[] = { 1, 4, 7, 9, 2, 3, 16 };
        solve(nums, 3);
    }

    static void solve(int nums[], int k) {
        if (nums.length < k) {
            System.out.println("Invalid");
            return;
        }
        int maxSum = 0;

        // First calculate the sum of first window
        for (int i = 0; i < k; i++) {
            maxSum += nums[i];
        }

        // Now shift the window
        int curSum = maxSum;
        for (int i = k; i < nums.length; i++) {
            curSum = nums[i] - nums[i - k] + curSum;
            maxSum = Math.max(maxSum, curSum);
        }

        System.out.println(maxSum);
    }
}
