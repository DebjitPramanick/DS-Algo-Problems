#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers. We have to find the number
of subsets whose sum is equal to given target sum.
*/

class CountSubsetSums{
    private:
        vector<int> nums = {2,3,5,6,8,10};
        int target = 10;
    public:

        // Recursion -------------------------------------------------

        int recur(vector<int> &v, int n, int t){
            // Base case
            if(t==0) return 1; // Number of null set = 1 as no target is given
            else if(n==0) return 0; // Number of sets is 0 as no elements are there
            
            // Code for different choices

            if(v[n-1]<=t){
                return recur(v, n-1, t-v[n-1]) + recur(v, n-1, t);
            }
            else if(v[n-1]>t) {
                return recur(v, n-1, t);
            }

            return 0;

        }

        // Top-Down -------------------------------------------------

        int topDown(int n, int t){
            // Base case

            int dp[n+1][t+1];
            for(int i=0;i<n+1;i++){
                for(int j=0;j<t+1;j++){
                    if(j==0) dp[i][j] = 1;
                    else if(i==0) dp[i][j] = 0;
                }
            }

            // Code for different choices

            for(int i=1;i<n+1;i++){
                for(int j=1;j<t+1;j++){
                    if(nums[i-1]<=j) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                    else dp[i][j] = dp[i-1][j];
                }
            }

            return dp[n][t];
            
        }


        void solve(){

            int ans;
            int n = nums.size();
            ans = recur(nums, n, target);
            cout<<"Number of subset sums: "<<ans<<endl;
            ans = topDown(n, target);
            cout<<"Number of subset sums: "<<ans<<endl;
        }

};

int main(){
    CountSubsetSums s;
    s.solve();
}