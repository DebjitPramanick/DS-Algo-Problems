package Algo_Problems.Sorting;

public class SelectionSort {
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

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
}

/*
 * 5 2 10 9 1 4 3 7
 * 1 5 10 9 2 4 3 7
 * 1 2 10 9 5 4 3 7
 * 1 2 3 10 9 5 4 7
 * 1 2 3 4 10 9 5 7
 * 1 2 3 4 5 10 9 7
 * 1 2 3 4 5 7 10 9
 * 1 2 3 4 5 7 9 10
 */