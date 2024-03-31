#include <bits/stdc++.h>
using namespace std;

// Buy and sell stocks with transaction fees
// Explanation: Pepcoding

// You are given an array prices where prices[i]
// is the price of a given stock on the ith day,
// and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may
// complete as many transactions as you like, but you
// need to pay the transaction fee for each transaction.
// Note: You may not engage in multiple transactions
// simultaneously (i.e., you must sell the stock before you buy again).

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
    int maxProfit(int fee)
    {
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    dp[ind][buy] = max(-prices[ind] - fee + dp[ind+1][0], dp[ind+1][1]);
                }
                else
                {
                    dp[ind][buy] = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
                }
            }
        }

        return dp[0][1];
    }

    int rec(int day, int buy, int fee)
    {
        if (day >= n)
        {
            return 0;
        }
        if(buy){
            return max(-prices[day]-fee+rec(day+1, 0, fee), rec(day+1, 1, fee));
        }
        return max(prices[day]+rec(day+1, 1, fee), rec(day+1, 0, fee));
    }
};

int main()
{
    Solution s({7, 1, 5, 3, 6, 4});
    int profit = s.maxProfit(10);
    cout << profit<<endl;
    profit = s.rec(0, 1, 10);
    cout << profit<<endl;
}
