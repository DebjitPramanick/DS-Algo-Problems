#include<bits/stdc++.h>
using namespace std;

/*
Given two strings. Find longest common sequence 
from both strings.

Ex:
s1: abcdgh
s2: abedfhr
LCS: abdh
*/

int dp[1002][1002];

class LCS{
    private:
        string x = "abcdgh", y = "abedfhr";
    public:

        // Recursive ---------------------------------------
        int rec(int m, int n){
            // Base case
            if(m==0 || n==0) return 0;

            // Code for different choices
            if(x[m-1]!=y[n-1]) 
                return max(rec(m-1, n), rec(m, n-1));
            
            return 1+rec(m-1, n-1);
        }

        // Memoization ---------------------------------------
        int memoization(int m, int n){
            // Base case
            if(m==0 || n==0) return 0;

            // Code for different choices
            if(dp[m][n]!=-1) return dp[m][n];
            if(x[m-1]!=y[n-1]) 
                return dp[m][n] = max(rec(m-1, n), rec(m, n-1));
            
            return dp[m][n] = 1+rec(m-1, n-1);
        }

        void solve(){
            int ans;
            ans = rec(x.size(), y.size());
            cout<<"LCS length is: "<<ans<<endl;
            ans = memoization(x.size(), y.size());
            cout<<"LCS length is: "<<ans<<endl;
        }

};

int main(){
    LCS s;
    memset(dp, -1, sizeof(dp));
    s.solve();
}