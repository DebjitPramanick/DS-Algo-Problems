#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers. We have to find if
the array can have two parts whose sums are equal.
*/

class EqualSumPartition{
    private:
        vector<int> nums = {1,5,11,5};
    public:

        // Recursion -------------------------------------------------

        bool recur(vector<int> &v, int n, int t){
            // Base case
            if(t==0) return true;
            else if(n==0) return false;
            
            // Code for different choices

            if(v[n-1]<=t){
                return recur(v, n-1, t-v[n-1]) || recur(v, n-1, t);
            }
            else if(v[n-1]>t) {
                return recur(v, n-1, t);
            }

            return false;

        }

        // Top-Down -------------------------------------------------

        bool topDown(int n, int t){
            // Base case

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
                    if(nums[i-1]<=j) dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    if(nums[i-1]>j) dp[i][j] = dp[i-1][j];
                }
            }

            return dp[n][t];
            
        }


        void solve(){

            bool ans;
            int n = nums.size(), sum=0;
            for(int i=0;i<n;i++) sum+=nums[i];
            if(sum%2!=0) {
                cout<<"No"<<endl;
                return;
            }
            ans = recur(nums, n, sum/2);
            ans? cout<<"Yes"<<endl : cout<<"No"<<endl;
            ans = topDown(n, sum/2);
            ans? cout<<"Yes"<<endl : cout<<"No"<<endl;
        }

};

int main(){
    EqualSumPartition s;
    s.solve();
}