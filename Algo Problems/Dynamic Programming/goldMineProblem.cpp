/*
Given a gold mine called M of (m x n) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.
*/


/*
Solution:

1. For each index calculate what is the max value with 
which we can enter it from the 0th column. The highest 
value at the last column is the answer.

2. Use memoization to reduce the time complexity.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(vector<vector<int>> M){
        int m = M.size();
        int n = M[0].size();
        int dp[m+2][n+2];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[j][i] =  M[j-1][i-1] + max(dp[j-1][i-1], max(dp[j][i-1], dp[j+1][i-1]));
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<=m;i++){
            ans = max(dp[i][n], ans);
        }

        cout<<"The answer is "<<ans<<endl;

    }
};

int main(){
    vector<vector<int>> M = {{1, 3, 3},
                             {2, 1, 4},
                             {0, 6, 4}};
    Solution s;
    s.solve(M);
}