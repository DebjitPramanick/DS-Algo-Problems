/*
Given a gold mine called M of (m x n) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.
*/


/*
Solution:

1. Use bottom up dynamic programming.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(vector<int> S, int n){
        int m = S.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i=0;i<m;i++){
            for(int j=S[i]; j<=n; j++) {
                dp[j] += dp[j-S[i]];
                cout<<dp[j]<< " ";
            }
            cout<<endl;
        }
        

        cout<<"The answer is "<<dp[n]<<endl;

    }
};

int main(){
    vector<int> S = {1,2,3};
    Solution s;
    s.solve(S,4);
}