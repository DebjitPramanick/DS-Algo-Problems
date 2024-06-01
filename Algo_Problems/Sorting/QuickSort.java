package Algo_Problems.Sorting;

/*
 * Key -> Select a pivot element and keep smaller elements before the pivot element and greater elements
 *after the pivot element. Then sort the smaller and greater elements again.
*/

public class QuickSort {
    public static void main(String[] args) {
        int nums[] = { 5, 2, 10, 9, 1, 4, 3, 7 };
        solve(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
    }

    static void solve(int nums[]) {
        quickSort(nums, 0, nums.length - 1);
    }

    static void quickSort(int nums[], int l, int r) {
        if (l < r) {
            int pivotIdx = partition(nums, l, r);
            quickSort(nums, l, pivotIdx - 1);
            quickSort(nums, pivotIdx + 1, r);
        }
    }

    static int partition(int nums[], int l, int r) {
        int pivotIdx = l - 1;
        int pivot = nums[r];

        for (int i = l; i < r; i++) {
            if (nums[i] < pivot) {
                pivotIdx++;
                swap(pivotIdx, i, nums);
            }
        }

        swap(pivotIdx + 1, r, nums);
        return pivotIdx + 1;
    }

    static void swap(int a, int b, int nums[]) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
