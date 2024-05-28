package Algo_Problems.BinarySearch;

/*
Searching in nearly sorted array
In nearly sorted array an element which should be at i-th position, may be at (i-1) or (i+1)
*/

public class SearchInNearlySortedArray {
    public static void main(String[] args) {
        int nums[] = { 5, 10, 30, 20, 40 };
        solve(nums, 20);
    }

    static void solve(int a[], int target) {
        int s = 0;
        int e = a.length - 1;
        int idx = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (a[mid] == target) {
                idx = mid;
                break;
            } else if (a[mid - 1] == target && (mid - 1 > s)) {
                idx = mid - 1;
                break;
            } else if (a[mid + 1] == target && (mid + 1 < e)) {
                idx = mid + 1;
                break;
            } else if (a[mid] > target) {
                e = mid - 2;
            } else
                s = mid + 2;
        }

        if (idx != -1) {
            System.out.println("Found at: " + idx);
        } else {
            System.out.println("FNot found");
        }
    }
}
