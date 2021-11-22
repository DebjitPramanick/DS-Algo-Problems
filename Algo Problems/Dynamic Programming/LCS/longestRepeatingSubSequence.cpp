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
    void solve(string s){
        s = ' '+s;
        int m = s.size();
        int dp[m][m];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<m;i++){
            for(int j=1;j<m;j++){
                // If characters match and indexes are not same
                if(s[i]==s[j] && i!=j) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout<<"The answer is "<<dp[m-1][m-1]<<endl;

    }
};

int main(){
    string str = "axxxmn";
    Solution s;
    s.solve(str);
}