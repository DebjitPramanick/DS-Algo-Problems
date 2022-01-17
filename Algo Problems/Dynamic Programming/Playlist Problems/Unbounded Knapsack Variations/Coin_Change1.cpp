#include<bits/stdc++.h>
using namespace std;

/*
Given an array of different coins and a target sum.
We have to find the number of ways by which using
those coins the target sum can be achieved.

Infinite supply of coins is available.
*/


class CoinChange{
    private:
        vector<int> coins = {1,2,3};
        int target = 5;
    public:

    int topDown(int n, int l){
            // Base case
            int dp[n+1][l+1];
            for(int i=0;i<n+1;i++){
                for(int j=0;j<l+1;j++){
                    if(j==0) dp[i][j] = 1;
                    else if(i==0) dp[i][j] = 0;
                }
            }

            // Code for different choices

            for(int i=1;i<n+1;i++){
                for(int j=1;j<l+1;j++){
                    if(coins[i-1]<=j){
                        // Getting max value by including and excluding
                        // a particular coin value
                        // Here including a length does not mean that we
                        // cannot use that length further, we can use.
                        // So index value is not reduced when including
                        // the length
                        dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                    }
                    else{
                       dp[i][j] = dp[i-1][j]; 
                    }
                }
            }

            return dp[n][l];
        } 

        void solve(){

            int ans;
            int n = coins.size();
            int ways = topDown(n, target);
            
            cout<<"Number of ways is: "<<ways<<endl;
        }

};

int main(){
    CoinChange s;
    s.solve();
}