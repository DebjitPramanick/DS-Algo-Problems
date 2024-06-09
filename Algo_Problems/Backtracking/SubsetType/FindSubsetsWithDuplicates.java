package Algo_Problems.Backtracking.SubsetType;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * Given an integer array nums that may contain duplicates, 
 * return all possible subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. 
 * Return the solution in any order.
 */

public class FindSubsetsWithDuplicates {
    static List<List<Integer>> ans = new ArrayList();

    public static void main(String[] args) {
        int nums[] = { 1, 2, 2 };
        Arrays.sort(nums);
        rec(0, nums, new ArrayList());

        for (List<Integer> l : ans) {
            for (Integer num : l) {
                System.out.print(num + " ");
            }
            System.out.println("");
        }
    }

    static void rec(int idx, int[] nums, List<Integer> temp) {
        List<Integer> t = new ArrayList(temp);
        ans.add(t);

        for (int i = idx; i < nums.length; i++) {
            if (i != idx && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.add(nums[i]);
            rec(i + 1, nums, temp);
            temp.removeLast();
        }
    }
}
