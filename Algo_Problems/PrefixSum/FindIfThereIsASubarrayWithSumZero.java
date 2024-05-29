package Algo_Problems.PrefixSum;

import java.util.HashMap;
import java.util.Map;

public class FindIfThereIsASubarrayWithSumZero {
    public static void main(String[] args) {
        int nums[] = { 4, 2, 3, 1, 6 };
        solve(nums);
    }

    static void solve(int nums[]) {
        int n = nums.length;
        int prefixSum[] = new int[n];
        Map<Integer, Boolean> mp = new HashMap<>();

        prefixSum[0] = nums[0];
        mp.put(prefixSum[0], true);
        boolean hasSubarrayWithSumZero = false;

        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
            if (mp.containsKey(prefixSum[i])) {
                hasSubarrayWithSumZero = true;
            } else {
                mp.put(prefixSum[i], true);
            }
        }

        if (hasSubarrayWithSumZero) {
            System.out.println("Has subarray with sum 0");
        } else {
            System.out.println("Couldn't find");
        }
    }
}
