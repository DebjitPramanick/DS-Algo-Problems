package Algo_Problems.Sorting;

public class MergeSort {
    public static void main(String[] args) {
        int nums[] = { 5, 2, 10, 9, 1, 4, 3, 7 };
        solve(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
    }

    static void solve(int nums[]) {
        mergeSort(nums, 0, nums.length - 1);
    }

    static void mergeSort(int nums[], int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    static void merge(int nums[], int l, int mid, int r) {
        int ln = mid - l + 1;
        int rn = r - mid;
        int left[] = new int[ln];
        int right[] = new int[rn];

        for (int i = 0; i < ln; i++)
            left[i] = nums[l + i];
        for (int i = 0; i < rn; i++)
            right[i] = nums[mid + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < ln && j < rn) {
            if (left[i] < right[j]) {
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < ln) {
            nums[k] = left[i];
            i++;
            k++;
        }
        while (j < rn) {
            nums[k] = right[j];
            j++;
            k++;
        }
    }
}
