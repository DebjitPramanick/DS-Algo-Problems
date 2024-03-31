#include<bits/stdc++.h>
using namespace std;

/*
Given an array p[] which represents the chain of matrices 
such that the ith matrix Ai is of dimension p[i-1] x p[i]. 
We need to write a function MatrixChainOrder() that should 
return the minimum number of multiplications needed to 
multiply the chain. 

Ex:
a: {40, 20, 30, 10, 30}
Output: 26000
*/


int static dp[1002][1002];
class MCM{
    private:
        vector<int> a = {40, 20, 30, 10, 30};
    public:

        // Memoization ---------------------------------------
        int memoization(vector<int> &ar, int i, int j){

            // Base case
            if(i>=j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];

            // Code for different choices
            int mn = INT_MAX;
            for(int k=i;k<=j-1;k++){
                int temp = rec(ar, i, k) + rec(ar, k+1, j) + ar[i-1]*ar[k]*ar[j];
                mn = min(mn, temp);
            }
            return dp[i][j] = mn;
        }

        // Recursion ---------------------------------------
        int rec(vector<int> &ar, int i, int j){

            // Base case
            if(i>=j) return 0;

            // Code for different choices
            int mn = INT_MAX;
            for(int k=i;k<=j-1;k++){
                int temp = rec(ar, i, k) + rec(ar, k+1, j) + ar[i-1]*ar[k]*ar[j];
                mn = min(mn, temp);
            }
            return mn;
        }

        void solve(){
            int ans;
            ans = rec(a, 1, a.size()-1);
            cout<<"Min cost is: "<<ans<<endl;
            ans = memoization(a, 1, a.size()-1);
            cout<<"Min cost is: "<<ans<<endl;
        }

};

int main(){
    MCM s;
    memset(dp, -1, sizeof(dp));
    s.solve();
}