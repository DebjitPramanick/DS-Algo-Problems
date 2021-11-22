/*
Given an array of integers, find the length of the longest 
(strictly) increasing subsequence from the given array.
*/


/*
Solution:

1. Use bottom up dynamic programming.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(vector<int> v){
        int n = v.size();
        int dp[n+1];
        for(int i=1;i<=n;i++) dp[i] = INT_MAX;
        dp[0] = INT_MIN;

        for(int i=0;i<n;i++){
            int idx = upper_bound(dp, dp+n+1, v[i]) - dp;
            if(v[i] > dp[idx-1] && v[i]<dp[idx]) dp[idx] = v[i];
        }

        int ma = 0;
        for(int i=n;i>=0;i--){
            if(dp[i]!=INT_MAX){
                ma = i;
                break;
            }
        }

        cout<<"The answer is "<<ma<<endl;

    }
};

int main(){
    vector<int> v = {5,8,3,7,9,1};
    Solution s;
    s.solve(v);
}