#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers and a target sum. We have to find if
there exists a subset whose sum is equal to target sum.
*/

// Memoization matrix
int dp[1002][1002];

class ZeroOneKnapsack{
    private:
        vector<int> nums = {2,3,7,8,10};
        int target = 38;
    public:

        // Recursion -------------------------------------------------

        bool recur(vector<int> &v, int t, int n){
            // Base case

            if(t==0) return true;
            else if(n==0) return false;

            // Code for different choices

            if(v[n-1]<=t){
                // We will take the max value between the weights of
                // including the current item and excluding the current item
                return recur(v, t-v[n-1], n-1) || recur(v, t, n-1);
            }
            if(v[n-1]>t){
                return recur(v, t, n-1);
            }

            return false;
        }


        void solve(){

            bool ans;
            int n = nums.size();
            ans = recur(nums, target, n);
            ans? cout<<"Yes"<<endl : cout<<"No"<<endl;
        }

};

int main(){
    memset(dp, -1, sizeof(dp));
    ZeroOneKnapsack s;
    s.solve();
}