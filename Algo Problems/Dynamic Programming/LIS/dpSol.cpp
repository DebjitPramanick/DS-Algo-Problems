/*
Given an array of integers, find the length of the longest 
(strictly) increasing subsequence from the given array.
*/

/*
Solution:

1. Use bottom up dynamic programming.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> v)
    {
        int n = v.size();
        int dp[n];
        memset(dp, 1, sizeof(dp));

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (v[i] > v[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        }

        // Return maximum value in lis[]
        int ans = *max_element(dp, dp + n);

        cout << "The answer is " << ans << endl;
    }
};

int main()
{
    vector<int> v = {5, 8, 3, 7, 9, 1};
    Solution s;
    s.solve(v);
}