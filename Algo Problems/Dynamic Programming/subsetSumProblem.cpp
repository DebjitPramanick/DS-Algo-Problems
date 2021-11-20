/*
Given an array arr[] of size N, check if it can be partitioned 
into two parts such that the sum of elements in both parts is 
the same.
*/


/*
Solution:

1. Use bottom up dynamic programming.
2. Check if the total sum is odd or even. If odd return false.
3. Create 2D DP array and each row should be of size sum/2
4. Iterate the array from last element
5. For each element, calculate results with including it and excluding it and store in dp
6. Return result

Time -> O(n*sum of els/2)
Time -> O(n*sum of els/2)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool util(int n, vector<vector<int>> &dp, int sum, vector<int> S){
        if(n == -1){
            if(sum==0) return 1;
            return 0;
        }
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(dp[n][sum]!=-1) return dp[n][sum];
        return dp[n][sum] = util(n-1, dp, sum-S[n], S) || util(n-1, dp, sum, S);
    }

    void solve(vector<int> S){
        int m = S.size();
        int sum = 0;
        for(int i=0;i<m;i++) sum += S[i];
        if(sum & 1) {
            cout<<"The answer is "<<false<<endl;
            return;
        }
        sum = sum/2;
        vector<vector<int>> dp(m, vector<int> (sum+1, -1));

        bool ans = util(m-1, dp, sum, S);
        
        cout<<"The answer is "<<ans<<endl;
    }
};

int main(){
    vector<int> S = {1, 5, 11, 5};
    Solution s;
    s.solve(S);
}