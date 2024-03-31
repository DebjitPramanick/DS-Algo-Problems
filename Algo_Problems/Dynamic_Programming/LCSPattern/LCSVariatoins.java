package Algo_Problems.Dynamic_Programming.LCSPattern;

import java.util.Collection;

class Solution {
    String a = "", b = "";

    public Solution(String _a, String _b) {
        this.a = _a;
        this.b = _b;
    }

    public void findLCS() {
        int m = a.length(), n = b.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        System.out.println("LCS is: " + dp[m][n]);
    }

    public void findLRS() {
        int m = a.length();
        int ans = Integer.MIN_VALUE;
        int[][] dp = new int[m + 1][m + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (a.charAt(i - 1) == a.charAt(j - 1) && i != j) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
                ans = Math.max(ans, dp[i][j]);
            }
        }
        System.out.println("LCS is: " + ans);
    }

}

public class LCSVariatoins {
    public static void main(String[] args) {
        Solution sol = new Solution("aabebcdd", "abedfhr");
        sol.findLCS();
        sol.findLRS();
    }
}