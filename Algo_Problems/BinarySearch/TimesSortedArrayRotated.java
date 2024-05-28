package Algo_Problems.BinarySearch;

// Find how many times a sorted array is rotated

/*

1. We have to find the minimum element in the rotated sorted array
2. For binary search the mid element must be less than both rigth and left element
3. Now we have to search for min element in the unsorted part of rotated sorted array

*/

public class TimesSortedArrayRotated {
    public static void main(String[] args) {
        int nums[] = { 15, 18, 2, 3, 6, 12 };
        solve(nums);
    }

    static void solve(int nums[]) {
        int n = nums.length;
        int s = 0, e = n - 1;
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int nxt = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            if (nums[mid] <= nums[nxt] && nums[mid] <= nums[prev]) {
                ans = mid;
                break;
            } else if (nums[mid] >= nums[s]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        System.out.println("Number of times rotated: " + ans);
    }
}
