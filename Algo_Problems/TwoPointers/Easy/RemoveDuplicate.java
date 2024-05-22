package Algo_Problems.TwoPointers.Easy;

public class RemoveDuplicate {
    public static void main(String[] args) {
        int nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        solve(nums);
    }

    static void solve(int nums[]) {
        if (nums.length < 2) {
            System.out.println(nums.length);
            return;
        }
        int i = 0, j = i + 1;

        while (j < nums.length) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }

        for (int k = 0; k < nums.length; k++) {
            System.out.print(nums[k] + " ");
        }
    }
}
