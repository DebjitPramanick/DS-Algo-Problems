package Algo_Problems.Backtracking.CombinationSum;

import java.util.ArrayList;
import java.util.List;

public class CombinationSum2 {
    public static void main(String[] args) {
        int nums[] = { 1, 4, 7, 5, 3, 3 };
        int sum = 11;
        solve(0, sum, nums, 0, new ArrayList<>());
    }

    static void solve(int sum, int target, int nums[], int i, List<Integer> ans) {
        if (sum == target) {
            for (Integer num : ans) {
                System.out.print(num + " ");
            }
            System.out.println("");
            return;
        }

        if (i == nums.length || sum > target) {
            return;
        }

        for (int j = i; j < nums.length; j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            ans.add(nums[j]);
            solve(sum + nums[j], target, nums, j + 1, ans);
            ans.removeLast();
        }
    }
}
