package Algo_Problems.Backtracking.PermutationType;

public class FindPossiblePermutation {
    public static void main(String[] args) {
        solve("abc", 0);
    }

    static void solve(String input, int idx) {
        if (idx == input.length()) {
            System.out.println(input);
            return;
        }

        for (int i = idx; i < input.length(); i++) {
            input = swap(input, idx, i);
            solve(input, idx + 1);
            input = swap(input, idx, i);
        }
    }

    static String swap(String origString, int a, int b) {
        char[] c = origString.toCharArray();
        char temp = c[a];
        c[a] = c[b];
        c[b] = temp;
        return new String(c);
    }
}
