package Algo_Problems.Dynamic_Programming.ZeroOneKnapsackVariations;

/*
Given an array of integers. We have to find the number
of subsets whose sum is equal to given target sum.
*/

public class CountSubsetSum {
    public static void main(String[] args) {
        int nums[] = { 2, 3, 5, 6, 8, 10 };
        int target = 16;
        solve(nums, target);
    }

    public static void solve(int nums[], int target) {
        int dp[][] = new int[nums.length + 1][target + 1];

        for (int i = 0; i <= nums.length; i++) {
            for (int j = 0; j <= target; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= nums.length; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else if (i == 0) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        System.out.println("Num of subsets: " + dp[nums.length][target]);
    }
}
