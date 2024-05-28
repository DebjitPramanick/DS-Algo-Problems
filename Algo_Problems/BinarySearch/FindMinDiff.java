package Algo_Problems.BinarySearch;

/*
 * Find min difference of elements from a key in sorted array
 */

public class FindMinDiff {
    public static void main(String[] args) {
        int nums[] = { 1, 3, 8, 10, 15 };
        solve(nums, 12);
        solve(nums, 5);
        solve(nums, 11);
        solve(nums, 32);
    }

    static void solve(int nums[], int key) {
        int s = 0, e = nums.length - 1;
        int diff = Integer.MAX_VALUE;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int tempDiff = Math.abs(nums[mid] - key);
            diff = Math.min(diff, tempDiff);
            if (nums[mid] <= key) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        System.out.println("Min diff: " + diff);
    }
}
