#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] 
// is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may 
// complete as many transactions as you like (i.e., 
// buy one and sell one share of the stock multiple 
// times) with the following restrictions:
// After you sell your stock, you cannot buy stock on 
// the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions 
// simultaneously (i.e., you must sell the stock before 
// you buy again).

class Solution
{
    vector<int> prices;
    int n = 0;

public:
    Solution(vector<int> _prices)
    {
        prices = _prices;
        n = prices.size();
    }
    int maxProfit()
    {
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                else
                {
                    dp[ind][buy] = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
                }
            }
        }

        return dp[0][1];
    }

    int rec(int day, int buy)
    {
        if (day >= n)
        {
            return 0;
        }
        if (buy)
        {
            return max(-prices[day] + rec(day + 1, 0), rec(day + 1, 1));
        }
        else
        {
            return max(prices[day] + rec(day + 2, 1), rec(day + 1, 0));
        }
    }
};

int main()
{
    Solution s({7, 1, 5, 3, 6, 4});
    int profit = s.maxProfit();
    cout << profit << endl;

    profit = s.rec(0, 1);
    cout << profit;
}
