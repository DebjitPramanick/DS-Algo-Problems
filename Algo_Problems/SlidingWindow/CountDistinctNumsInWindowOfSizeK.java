package Algo_Problems.SlidingWindow;

import java.util.HashMap;
import java.util.Map;

public class CountDistinctNumsInWindowOfSizeK {
    public static void main(String[] args) {
        int nums[] = { 1, 2, 1, 3, 4, 2, 3 };
        int k = 4;

        solve(nums, k);
    }

    static void solve(int nums[], int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < k; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], 1);
            } else {
                map.put(nums[i], map.get(nums[i]) + 1);
            }
        }

        System.out.println(map.size());

        for (int i = k; i < nums.length; i++) {

            if (map.get(nums[i - k]) == 1) {
                map.remove(nums[i - k]);
            }

            else
                map.put(nums[i - k], map.get(nums[i - k]) - 1);

            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);

            System.out.println(map.size());
        }

    }
}
