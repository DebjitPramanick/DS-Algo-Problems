/*
Given a fence with n posts and k colors, find out the 
number of ways of painting the fence so that not more 
than two consecutive fences have the same colors. Since 
the answer can be large return it modulo 10^9 + 7.
*/


/*
Solution:
 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void solve(int N, int k){
        
        vector<long> dp(N+1,0);
        dp[1] = k; // There are k ways to color first post
        int same = 0, diff = k;

        for(int i=2;i<=N;i++){
            same = diff; // Current same is same as previous diff
            diff = dp[i-1]*(k-1);
            dp[i] = (same+diff); //Total choice till i
        } 

        cout<<"The answer will be: "<<dp[N]<<endl;
    }
};

int main(){
    Solution s;
    int k = 2;
    s.solve(3, k);
}