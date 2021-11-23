/*
Given an array of n positive integers. Write a program 
to find the sum of maximum sum subsequence of the given 
array such that the integers in the subsequence are sorted 
in increasing order. For example, if input is 
{1, 101, 2, 3, 100, 4, 5}, then output should be 106 
(1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, 
then output should be 22 (3 + 4 + 5 + 10) 
and if the input array is {10, 5, 4, 3}, then output 
should be 10
*/

/*
Solution:

1. Variation of LIS problem (Longest Increasing Subsequence)
2. Use bottom up dynamic programming.

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

        for (int i = 0; i < n; i++) dp[i] = v[i];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (v[i] > v[j] && dp[i] < dp[j] + v[i])
                    dp[i] = dp[j] + v[i];
        }

        // Return maximum value in lis[]
        int ans = *max_element(dp, dp + n);

        cout << "The answer is " << ans << endl;
    }
};

int main()
{
    vector<int> v = {1, 101, 2, 3, 100, 4, 5};
    Solution s;
    s.solve(v);
}