package Algo_Problems.SlidingWindow;

import java.util.HashMap;
import java.util.Map;

/*
 * Given an array arr[] of size n containing integers. The problem is to find the length of the longest sub-array having sum equal to the given value k.
 */

public class LongestSubArrayWthSumK {
    public static void main(String args[]) {
        int nums[] = { -7, -11, -3, -7, 4, 15, -13, 18, -10, -10 };
        int k = 23;
        solve2(nums, k);
    }

    static void solve(int nums[], int k) { // This approach will not work for negative numbers
        int ans = Integer.MIN_VALUE;
        int curSum = 0;
        int s = 0, e = 0;

        for (int i = 0; i < nums.length; i++) {
            while (curSum < k && e < nums.length) {
                curSum += nums[e++];
            }

            if (curSum == k) {
                ans = Math.max(ans, e - s);
            }

            curSum -= nums[s];
            s++;
        }

        System.out.println("Max length: " + ans);
    }

    static void solve2(int nums[], int k) { // This approach will work for negative numbers also
        HashMap<Integer, Integer> sum_index_map = new HashMap<>();
        int maxLen = 0;
        int prefix_sum = 0;

        for (int i = 0; i < nums.length; i++) {
            prefix_sum += nums[i];

            if (prefix_sum == k) {
                maxLen = i + 1;
            }

            else if (sum_index_map.containsKey(prefix_sum - k)) {
                maxLen = Math.max(
                        maxLen,
                        i - sum_index_map.get(prefix_sum - k));
            }

            if (!sum_index_map.containsKey(prefix_sum)) {
                sum_index_map.put(prefix_sum, i);
            }
        }

        System.out.println("Max length: " + maxLen);
    }
}
