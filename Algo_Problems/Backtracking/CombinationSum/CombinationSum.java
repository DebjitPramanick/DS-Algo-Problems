package Algo_Problems.Backtracking.CombinationSum;

import java.util.ArrayList;
import java.util.List;

public class CombinationSum {

    public static void main(String[] args) {
        int nums[] = { 1, 4, 7 };
        solve(nums, 0, new ArrayList<>());
    }

    static void solve(int nums[], int i, List<Integer> ans) {
        if (i == nums.length) {
            for (Integer num : ans) {
                System.out.print(num + " ");
            }
            System.out.println("");
            return;
        }

        solve(nums, i + 1, ans);
        ans.add(nums[i]);
        solve(nums, i + 1, ans);
        ans.removeLast();
    }
}
