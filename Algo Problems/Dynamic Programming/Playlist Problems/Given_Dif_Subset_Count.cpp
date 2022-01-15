#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers. We have to find the minimum
difference of subset sums.
*/

class GivenDifSubsetCount{
    private:
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        int dif = 1;
    public:

        int getSubsetSumCount(int n, int t){

            // Simple coun subset sum problem
            
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
                    if(nums[i-1]<=j) dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                    else if(nums[i-1]>j) dp[i][j] = dp[i-1][j];
                }
            }

            return dp[n][t];
        }


        void solve(){

            int ans = 0;
            int n = nums.size(), sumRange = 0;

            // Find range of sum
            for(int i=0;i<n;i++) sumRange+=nums[i];
            // Min sum range = 0, Max sum range = 23 [For this case]

            /*
            s1 - s2 = dif
            s1 + s2 = sumRange

            => 2 * s1 = dif + sumRange
            => s1 = (dif + sumRange) / 2
            */

            int reqSum = (dif+sumRange)/2;

            ans = getSubsetSumCount(n, reqSum);
            cout<<"Count of subset sum with given difference is: "<<ans<<endl;
        }

};

int main(){
    GivenDifSubsetCount s;
    s.solve();
}