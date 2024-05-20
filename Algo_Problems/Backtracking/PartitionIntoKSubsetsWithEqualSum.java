package Algo_Problems.Backtracking;

/*
 * Given an integer array of N elements, the task is to 
 * divide this array into K non-empty subsets such that 
 * the sum of elements in every subset is same. All elements 
 * of this array should be part of exactly one partition.
 */

public class PartitionIntoKSubsetsWithEqualSum {
    public static void main(String[] args) {
        int nums[] = { 2, 1, 5, 5, 6 };
        System.out.println(isPossible(nums, 3));
        int nums2[] = { 2, 1, 4, 5, 6 };
        System.out.println(isPossible(nums2, 3));
    }

    static boolean isPossible(int nums[], int k) {

        if (nums.length < k) {
            return false;
        }
        if (k == 1) {
            return true;
        }

        int sum = 0;

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }

        if (sum % k != 0) {
            return false;
        }

        int target = sum / k;
        boolean used[] = new boolean[nums.length];

        for (int i = 0; i < nums.length; i++) {
            used[i] = false;
        }

        return isPossibleRec(nums, 0, k, target, 0, used);
    }

    static boolean isPossibleRec(int nums[], int i, int k, int target, int subsetSum, boolean used[]) {
        if (k == 0) {
            return true;
        }

        if (subsetSum == target) {
            return isPossibleRec(nums, 0, k - 1, target, 0, used);
        }

        for (int j = i; j < nums.length; j++) {
            if (used[j] || subsetSum + nums[j] > target) {
                continue;
            }
            used[j] = true;
            if (isPossibleRec(nums, j + 1, k, target, subsetSum + nums[j], used)) {
                return true;
            }
            used[j] = false;
        }

        return false;
    }
}
