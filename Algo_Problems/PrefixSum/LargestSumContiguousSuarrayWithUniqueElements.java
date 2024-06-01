package Algo_Problems.PrefixSum;

import java.util.HashSet;
import java.util.Set;

public class LargestSumContiguousSuarrayWithUniqueElements {
    public static void main(String[] args) {

        int nums[] = { 1, 2, 3, 3, 4, 5, 2, 1 };
        solve(nums);

    }

    static void solve(int nums[]) {
        int i = 0, j = 0, sum = 0, maxSum = 0;
        Set<Integer> set = new HashSet<>();
        set.add(nums[0]);
        sum = nums[0];
        maxSum = sum;

        while (j < nums.length) {
            if (!set.contains(nums[j])) {
                sum += nums[j];
                maxSum = Math.max(maxSum, sum);
                set.add(nums[j++]);
            } else {
                sum -= nums[i];
                set.remove(nums[i++]);
            }
        }

        System.out.println("Max sum: " + maxSum);
    }
}
