package Algo_Problems.Sorting;

/*
 * This method is only applicable when given array 
 * values or elements are in the range of 1 to N or
 * 0 to N. In this method, we do not need to rotate an array
 */

public class CycleSortOneToN {
    public static void main(String[] args) {
        int[] nums = { 3, 2, 4, 5, 1 };
        int n = nums.length;
        solve(nums, n);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
    }

    static void solve(int nums[], int n) {
        int i = 0;

        while (i < n) {
            int correctPos = nums[i] - 1; // Because array index starts from 0
            if (nums[i] < n && nums[i] != nums[correctPos]) {
                int temp = nums[correctPos];
                nums[correctPos] = nums[i];
                nums[i] = temp;
            } else {
                i++;
            }
        }
    }
}
