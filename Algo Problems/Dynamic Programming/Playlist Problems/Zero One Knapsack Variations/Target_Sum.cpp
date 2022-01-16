#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers and a target sum. We have to put
'+/-' signs before each array element to get target sum. 
Thus we have to return the number of such type of combinations.
*/

/*
This problem is a variation of
-> Find subsets count of given difference
*/

class TargetSum{
    private:
        vector<int> nums = {1,1,2,3};
        int target = 1;
    public:

        int getSubsetSumCount(int t){
            // Base case

            int n = nums.size();
            int dp[n+1][t+1];

            dp[0][0] = 1;
            for(int i=1;i<t+1;i++)
                dp[0][i] = 0;

            // Code for different choices

            for(int i=1;i<n+1;i++){
                for(int j=0;j<t+1;j++){
                    if(nums[i-1]<=j){
                        dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                    }
                    if(nums[i-1]>j){
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }

            return dp[n][t];
        }


        void solve(){

            int ans;
            int n = nums.size();
            int sum = 0;
            for(int i=0;i<n;i++) sum+=nums[i];
            if (abs(target) > sum || (sum + target) % 2 != 0){ 
                // For handling certain testcases
                return;
            }
            int t = (target+sum)/2;
            ans = getSubsetSumCount(t);
            cout<<"No. of combinations is: "<<ans<<endl;
        }

};

int main(){
    TargetSum s;
    s.solve();
}