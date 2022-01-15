#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers. We have to find the minimum
difference of subset sums.
*/

class MinSubsetSumDif{
    private:
        vector<int> nums = {1,2,7};
    public:

        vector<int> isSumPossible(int n, int t){

            // At first we will check if certain subset sum is present in array
            // Then we will only store the last row of topdown matrix

            
            // Base case

            int dp[n+1][t+1];
            vector<int> res;

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
                    else if(nums[i-1]>j) dp[i][j] = dp[i-1][j];
                }
            }

            // Storing last row of topdown matrix to store
            // the possible subset sums

            for(int i=0;i<t+1;i++){
                if(dp[n][i]) res.push_back(i);
            }

            return res;
        }


        void solve(){

            int ans = INT_MAX;
            int n = nums.size(), sumRange = 0;

            // Find range of sum
            for(int i=0;i<n;i++) sumRange+=nums[i];
            // Min sum range = 0, Max sum range = 23 [For this case]

            vector<int> s = isSumPossible(n, sumRange);

            int size = s.size();
            for(int i=0;i<size/2;i++){
                /*
                Dif = s2 - s1
                Now, s2 = sumRange - s1
                So Dif = sumRange - 2*s1
                ans we have to iterate the array till n/2-th index.
                */
                ans = min(ans, sumRange-2*s[i]);
            }
            cout<<"Min subset sum difference is: "<<ans<<endl;
        }

};

int main(){
    MinSubsetSumDif s;
    s.solve();
}