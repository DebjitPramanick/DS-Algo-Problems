#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers and a target sum. We have to find if
there exists a subset whose sum is equal to target sum.
*/

class ZeroOneKnapsack{
    private:
        vector<int> nums = {2,3,7,8,10};
        int target = 8;
    public:

        // Recursion -------------------------------------------------

        bool recur(vector<int> &v, int t, int n){
            // Base case

            if(t==0) return true;
            else if(n==0) return false;

            // Code for different choices

            if(v[n-1]<=t){
                return recur(v, t-v[n-1], n-1) || recur(v, t, n-1);
            }
            if(v[n-1]>t){
                return recur(v, t, n-1);
            }

            return false;
        }

        // Top-Down -------------------------------------------------

        bool topDown(){
            // Base case

            int n = nums.size(), t = target;
            int dp[n+1][t+1];

            for(int i=0;i<n+1;i++){
                for(int j=0;j<t+1;j++){
                    if(j==0) dp[i][j] = true;
                    else if(i==0) dp[i][j] = false;
                }
            }

            // Code for different choices

            for(int i=1;i<n+1;i++){
                for(int j=1;j<t+1;j++){
                    if(nums[i-1]<=j){
                        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    }
                    if(nums[i-1]>j){
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }

            return dp[n][t];
        }


        void solve(){

            bool ans;
            int n = nums.size();
            ans = recur(nums, target, n);
            ans? cout<<"Yes"<<endl : cout<<"No"<<endl;
            ans = topDown();
            ans? cout<<"Yes"<<endl : cout<<"No"<<endl;
        }

};

int main(){
    ZeroOneKnapsack s;
    s.solve();
}