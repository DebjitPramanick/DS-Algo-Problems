package Algo_Problems.BinarySearch;

public class SearchInRotatedList {
    public static void main(String[] args) {
        int nums[] = { 56, 67, 1, 4, 5, 15, 32, 46 };
        searchInRotatedList(nums, 23);
    }

    static void searchInRotatedList(int nums[], int num) {
        int s = 0, e = nums.length - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == num) {
                System.out.println("Found: " + mid);
                return;
            } else if (nums[mid] >= nums[s]) {
                if (num >= nums[s] && num <= nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else if (nums[e] >= nums[mid]) {
                if (num >= nums[mid] && num <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        System.out.println("Not found");
    }
}
