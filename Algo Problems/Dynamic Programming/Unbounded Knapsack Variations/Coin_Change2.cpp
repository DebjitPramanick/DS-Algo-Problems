#include<bits/stdc++.h>
using namespace std;

/*
Given an array of different coins and a target sum.
We have to find the number of ways by which using
those coins the target sum can be achieved and number
of coins used is minimum.

Basically we have to minimize number of coins.

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
                    if(i==0) dp[i][j] = INT_MAX-1; 
                    // To get sum = i, min coins  = Infinity (Mathematically)
                    if(j==0) dp[i][j] = 0; // To get sum = 0, min coins  = 0
                }
            }

            // Code for second base case

            for(int i=1;i<n+1;i++){
                for(int j=1;j<l+1;j++){
                    if(j%coins[i-1]==0){
                        // If sum is divisible by first coin,
                        // store the number of those coins required
                        // to make the sum
                        // Do it for whole matrix
                        dp[i][j] = j/coins[i-1];
                    }
                    else{
                       dp[i][j] = INT_MAX - 1;
                    }
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
                        dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
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
            
            cout<<"Number of ways(Min coins) is: "<<ways<<endl;
        }

};

int main(){
    CoinChange s;
    s.solve();
}