package Algo_Problems.Backtracking.PermutationType;

public class FindPossiblePermutationWithSpace {
    public static void main(String[] args) {
        solve("abc", 0, 3);
    }

    static void solve(String input, int idx, int n) {
        if (idx == n - 1) {
            System.out.println(input);
            return;
        }
        StringBuilder builder = new StringBuilder(input);

        solve(input, idx + 1, n);

        builder.insert(idx + 1, '_');
        input = builder.toString();

        solve(input, idx + 2, n + 1);

        builder.deleteCharAt(idx + 1);
        input = builder.toString();
    }
}
