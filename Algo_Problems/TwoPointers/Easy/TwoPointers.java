package Algo_Problems.TwoPointers.Easy;

/*
 * Two pointers is really an easy and effective technique that is 
 * typically used for searching pairs in a sorted array. 
 * 
 * Problem: 
 * Given a sorted array A (sorted in ascending order), having N integers, 
 * find if there exists any pair of elements (A[i], A[j]) such that 
 * their sum is equal to X.
 */

public class TwoPointers {
    public static void main(String[] args) {
        int nums[] = { 10, 20, 35, 50, 70, 80 };
        int target = 90;
        solve(nums, target);
    }

    static void solve(int nums[], int target) {
        int i = 0, j = nums.length - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                System.out.println("Found: " + nums[i] + " " + nums[j]);
                i++;
                j--;
            }
            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
    }
}
