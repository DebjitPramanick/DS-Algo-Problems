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
    vector<int> prices;
    int n = 0, capacity = 0;

public:
    int profit;
    Solution(vector<int> _v)
    {
        prices = _v;
        n = prices.size();
    }

    int recursion(int day, int buy, int cap)
    {
        if (cap == 0)
            return 0;
        if (day == n)
            return 0;
        if (buy)
            profit = max(-prices[day] + recursion(day + 1, 0, cap), recursion(day + 1, 1, cap));
        else
            profit = max(prices[day] + recursion(day + 1, 1, cap - 1), recursion(day + 1, 0, cap));
        return profit;
    }

    int maxProfit()
    {
        if (prices.size() == 0)
            return 0;
        int k = 2;
        int dp[k + 1][prices.size()];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= k; i++)
        {
            int max_profit = INT_MIN;
            for (int j = 1; j < prices.size(); j++)
            {
                if (dp[i - 1][j - 1] - prices[j - 1] > max_profit)
                    max_profit = dp[i - 1][j - 1] - prices[j - 1];

                dp[i][j] = max(dp[i][j - 1], prices[j] + max_profit);
            }
        }
        return dp[k][prices.size() - 1];
    }
};

int main()
{
    Solution s({7, 1, 5, 3, 6, 4});
    int profit = s.recursion(0, 1, 2);
    cout << profit<<endl;
    profit = s.maxProfit();
    cout << profit;
}
