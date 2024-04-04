package Algo_Problems.Dynamic_Programming.UnboundedKnapsackVariations;

public class CoinChange {
    public static void main(String[] args) {
        int coins[] = {1,2,3};
        int target = 5;
        solve(coins, target);
    }

    static void solve(int coins[], int target) {
        int m = coins.length;
        int dp[][] = new int[m+1][target+1];

        for(int i=0;i<=m;i++){
            for(int j=0;j<=target;j++) {
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=target;j++) {
                if(coins[i-1]<=j) dp[i][j] =  dp[i][j-coins[i-1]] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        System.out.println("The number of combinations is: "+ dp[m][target]);
    }
}
