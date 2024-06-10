package Algo_Problems.Dynamic_Programming.ZeroOneKnapsackVariations;

public class Practice {
    public static void main(String[] args) {
        int nums[] = { 2, 3, 7, 8, 10 };
        int sum = 8;
        solve(nums, sum);
    }

    public static void solve(int nums[], int sum) {
        boolean dp[][] = new boolean[nums.length + 1][sum + 1];

        for (int i = 0; i <= nums.length; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                }
            }
        }

        for (int i = 1; i <= nums.length; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        System.out.println("Exists: " + dp[nums.length][sum]);
    }
}
