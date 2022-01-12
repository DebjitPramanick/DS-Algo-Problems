#include<bits/stdc++.h>
using namespace std;

/*
The 0/1 knapsack problem means that the items 
are either completely or no items are filled 
in a knapsack. For example, we have two items 
having weights 2kg and 3kg, respectively. If 
we pick the 2kg item then we cannot pick 1kg 
item from the 2kg item (item is not divisible); 
we have to pick the 2kg item completely.
*/

// Memoization matrix
int dp[1002][1002];

class ZeroOneKnapsack{
    private:
        vector<int> weights = {1,3,4,5};
        vector<int> values = {1,4,5,7};
        int limit = 7;
    public:

        // Recursion -------------------------------------------------

        int recur(vector<int> &w, vector<int> &v, int l, int n){
            // Base case

            if(n==0 || l==0) return 0;

            // Code for different choices

            if(w[n-1]<=l){
                // We will take the max value between the weights of
                // including the current item and excluding the current item
                return max(v[n-1]+recur(w, v, l-w[n-1], n-1), recur(w, v, l, n-1));
            }
            if(w[n-1]>l){
                return recur(w, v, l, n-1);
            }

            return 0;
        }

        // Memoization -----------------------------------------------
        // Take the variables whose values are changing and create a 
        // matrix to store value
        // Here weight limit and size of array are changing
        
        int memoization(vector<int> &w, vector<int> &v, int l, int n){
            // Base case
            if(n==0 || l==0) return 0;

            // Code for different choices

            if(dp[n][l]!=-1) return dp[n][l];

            if(w[n-1]<=l){
                // We will take the max value between the weights of
                // including the current item and excluding the current item
                dp[n][l] = max(v[n-1]+recur(w, v, l-w[n-1], n-1), recur(w, v, l, n-1));
                return dp[n][l];
            }

            dp[n][l] = recur(w, v, l, n-1);
            return dp[n][l];
        } 
        
        void solve(){

            int maxProfit = 0;
            int n = weights.size();
            // maxProfit = recur(weights, values, limit, n);
            maxProfit = memoization(weights, values, limit, n);
            cout<<"Max profit is: "<<maxProfit<<endl;
        }

};

int main(){
    memset(dp, -1, sizeof(dp));
    ZeroOneKnapsack s;
    s.solve();
}