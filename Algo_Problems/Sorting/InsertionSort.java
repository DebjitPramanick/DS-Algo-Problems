package Algo_Problems.Sorting;

public class InsertionSort {
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

        for (int i = 1; i < n; i++) {
            int cur = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > cur) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = cur;
        }
    }
}

/*
 * 2 5 10 9 1 4 3 7
 * 2 5 9 10 1 4 3 7
 * 1 2 5 9 10 4 3 7
 * 1 2 4 5 9 10 3 7
 * 1 2 3 4 5 9 10 7
 * 1 2 3 4 5 7 9 10
 */