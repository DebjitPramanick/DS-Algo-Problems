package Algo_Problems.PrefixSum;

public class PrefixSum {
    public static void main(String[] args) {
        int nums[] = { 10, 4, 16, 20 };
        solve(nums);
    }

    static void solve(int nums[]) {
        int n = nums.length;
        int prefixSum[] = new int[n];
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }

        System.out.println("Prefix sum");
        for (int i = 0; i < n; i++) {
            System.out.print(prefixSum[i] + " ");
        }
    }
}
