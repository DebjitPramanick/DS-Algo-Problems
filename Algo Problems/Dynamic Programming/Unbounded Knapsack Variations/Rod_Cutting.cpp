#include <bits/stdc++.h>
using namespace std;

/*
Given two arrays length and price and one integer
which represents length of rod. We have to find
max profit by cutting the rod in different lengths.

We can cut the rod of same length for multiple times.
*/

class RodCutting
{
private:
    vector<int> lengths = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int length = 8;

public:
    int topDown(int n, int l)
    {
        // Base case
        int dp[n + 1][l + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < l + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        // Code for different choices

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < l + 1; j++)
            {
                if (lengths[i - 1] <= j)
                {
                    // Getting max value by including and excluding
                    // a particular length
                    // Here including a length does not mean that we
                    // cannot use that length further, we can use.
                    // So index value is not reduced when including
                    // the length
                    dp[i][j] = max(prices[i - 1] + dp[i][j - lengths[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][l];
    }

    int topDownV2(int n, int l)
    {
        // Base case
        // 1D DP Space Optimization
        vector<int> previous(n + 1, 0);

        // Code for different choices

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < l + 1; j++)
            {
                if (lengths[i - 1] <= j)
                {
                    previous[j] = max(prices[i - 1] + previous[j - lengths[i - 1]], previous[j]);
                }
            }
        }

        for (auto x : previous)
        {
            cout << x << " ";
        }
        cout << endl;

        return previous[l];
    }

    void solve()
    {

        int ans;
        int n = lengths.size();
        int maxProfit = topDown(n, length);
        cout << "Max profit is: " << maxProfit << endl;
        maxProfit = topDownV2(n, length);
        cout << "Max profit is: " << maxProfit << endl;
    }
};

int main()
{
    RodCutting s;
    s.solve();
}