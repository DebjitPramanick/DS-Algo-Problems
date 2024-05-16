package Algo_Problems.Backtracking.SubsetType;

import java.util.ArrayList;
import java.util.List;

public class FindPossibleSubsets {

    public static void main(String[] args) {
        int[] nums = { 1, 4, 7 };
        solve(nums, 0, new ArrayList<>());
    }

    static void solve(int[] nums, int i, List<Integer> list) {
        if (i == nums.length) {
            for (Integer num : list) {
                System.out.print(num + " ");
            }
            System.out.println("");
            return;
        }

        solve(nums, i + 1, list);
        list.add(nums[i]);
        solve(nums, i + 1, list);
        list.removeLast();
    }
}
