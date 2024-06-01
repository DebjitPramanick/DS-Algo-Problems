package Algo_Problems.Sorting;

public class BubbleSort {
    public static void main(String[] args) {
        int nums[] = { 5, 2, 10, 9, 1, 4, 3, 7 };
        solve(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
    }

    static void solve(int nums[]) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
}

/*
 * 5, 2, 10, 9, 1, 4, 3, 7
 * 2, 5, 9, 1, 4, 3, 7, 10
 * 2, 5, 1, 4, 3, 7, 9, 10
 * 2, 1, 4, 3, 5, 7, 9, 10
 * 1, 2, 3, 4, 5, 7, 9, 10
 */