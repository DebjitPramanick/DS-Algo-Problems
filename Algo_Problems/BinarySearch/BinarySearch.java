package Algo_Problems.BinarySearch;

public class BinarySearch {
    public static void main(String[] args) {
        int nums[] = { 1, 7, 9, 9, 12, 31, 34, 34, 78 };
        simpleBS(nums, 34);
    }

    static void simpleBS(int nums[], int num) {
        int s = 0, e = nums.length - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == num) {
                System.out.println("Found: " + mid);
                return;
            } else if (nums[mid] < num)
                s = mid + 1;
            else
                e = mid - 1;
        }

        System.out.println("Not found");
    }

}
