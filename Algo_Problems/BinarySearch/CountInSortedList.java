package Algo_Problems.BinarySearch;

public class CountInSortedList {
    public static void main(String[] args) {
        int nums[] = { 1, 7, 9, 9, 12, 31, 34, 34, 34, 34, 78 };
        solve(nums, 34);
    }

    private static int gteFirstIndex(int nums[], int target) {
        int s = 0, e = nums.length;
        int idx = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                idx = mid;
                e = mid - 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return idx;
    }

    private static int gteLastIndex(int nums[], int target) {
        int s = 0, e = nums.length;
        int idx = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                idx = mid;
                s = mid + 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return idx;
    }

    static void solve(int nums[], int target) {
        int firstIndex = gteFirstIndex(nums, target);
        int lastIndex = gteLastIndex(nums, target);

        System.out.println("Count: " + (lastIndex - firstIndex + 1));
    }
}
