#include <bits/stdc++.h>
using namespace std;
/*
Buy ans sell stocks with atmost 2 transaction

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int k = 2;
        int dp[k + 1][prices.size()];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= k; i++)
        {
            int max_temp = INT_MIN;
            for (int j = 1; j < prices.size(); j++)
            {
                if (dp[i - 1][j - 1] - prices[j - 1] > max_temp)
                    max_temp = dp[i - 1][j - 1] - prices[j - 1];

                dp[i][j] = max(dp[i][j - 1], prices[j] + max_temp);
            }
        }
        return dp[k][prices.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = s.maxProfit(prices);
    cout << profit;
}
