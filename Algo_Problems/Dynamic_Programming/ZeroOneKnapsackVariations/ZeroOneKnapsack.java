package Algo_Problems.Dynamic_Programming.ZeroOneKnapsackVariations;

public class ZeroOneKnapsack{
    public static void main(String args[]) {
        int weights[] = {1,3,4,5};
        int values[] = {1,4,5,7};
        int limit = 7;
        solve(weights, values, limit);
    }

    static void solve(int weights[], int values[], int limit) {
        int m = weights.length;
        int dp[][] = new int[m+1][limit+1];

        for(int i=0;i<=m;i++) {
            for(int j=0;j<=limit;j++) {
                if(i==0 || j ==0) {
                    dp[i][j] = 0;
                }
            }
        }

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=limit;j++) {
                if(weights[i-1]<=j) {
                    dp[i][j] = Math.max(values[i-1]+dp[i-1][j-weights[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] =  dp[i-1][j];
                }
            }
        }

        System.out.println("Result is: " + dp[m][limit]);
    }
}