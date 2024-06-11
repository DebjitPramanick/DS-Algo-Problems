package Algo_Problems.Dynamic_Programming.BuyNSell_Stocks;

class Solution {
    int[] prices;

    public Solution(int[] prices) {
        this.prices = prices;
    }

    public void withOneTransaction() {
        if (prices.length == 0) {
            return;
        }
        int profit = 0;
        int buyPrice = prices[0];

        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }
            profit = Math.max(prices[i] - buyPrice, profit);
        }

        System.out.println("Max profit ==> " + profit);
    }

    public void withAnyTransactions() {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        System.out.println("Max profit: " + profit);
    }

    public void withTwoTransactions() {
        int n = prices.length;
        int k = 2;

        int[][] dp = new int[k + 1][n];
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < n; j++)
                dp[i][j] = 0;
        }

        for (int i = 1; i <= k; i++) {
            int max_profit = Integer.MIN_VALUE;
            for (int j = 1; j < n; j++) {
                if (dp[i - 1][j - 1] - prices[j - 1] > max_profit)
                    max_profit = -prices[j - 1] + dp[i - 1][j - 1]; // Getting max profit after first sell and second
                                                                    // buy

                // Maximum of not making a transaction (sell) on j th day and selling today
                // after buying the stock on mth day
                dp[i][j] = Math.max(dp[i][j - 1], prices[j] + max_profit);
            }
        }

        System.out.println("Max profit ==> " + dp[k][n - 1]);

    }

    public void withTransactionFees(int fee) {
        int buy = Integer.MIN_VALUE;
        int sell = 0;
        for (int i = 0; i < prices.length; i++) {
            buy = Math.max(buy, -prices[i] + sell);
            sell = Math.max(sell, buy + prices[i] - fee);
        }
        System.out.println("Max profit: " + sell);
    }

    public void withCoolDown() {
        int n = this.prices.length;
        int[][] dp = new int[n + 2][2];

        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int profit;
            for (int j = 0; j < 2; j++) {
                if (j == 1) {
                    profit = Math.max(dp[i + 1][0] - prices[i], dp[i + 1][1]); // Max of sell or not sell
                } else {
                    profit = Math.max(dp[i + 2][1] + prices[i], dp[i + 1][0]); // Max of buy or not buy
                }
                dp[i][j] = profit;
            }
        }

        System.out.println("Max profit: " + dp[0][1]);
    }
}

public class BuyNSellStocks {
    public static void main(String[] args) {
        Solution sol = new Solution(new int[] { 7, 1, 5, 3, 6, 4 });

        sol.withOneTransaction();

        sol.withTwoTransactions();

        sol.withAnyTransactions();

        sol.withTransactionFees(1);

        sol.withCoolDown();
    }
}
