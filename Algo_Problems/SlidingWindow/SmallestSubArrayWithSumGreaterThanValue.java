package Algo_Problems.SlidingWindow;

public class SmallestSubArrayWithSumGreaterThanValue {
    public static void main(String[] args) {
        int nums[] = { 1, 4, 45, 6, 10, 19 };
        int x = 51;
        solve(nums, x);
    }

    static void solve(int nums[], int x) {
        int s = 0, e = 0;
        int sum = 0;
        int ans = Integer.MAX_VALUE;

        while (e < nums.length) {
            while (sum <= x && e < nums.length) {
                sum += nums[e++];
            }

            while (sum > x && s < nums.length) {
                ans = Math.min(e - s, ans);
                sum -= nums[s++];
            }
        }

        System.out.println("Ans is: " + ans);
    }
}
