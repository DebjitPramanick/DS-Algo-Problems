/*
Given an array arr[] of size N, check if it can be partitioned 
into two parts such that the sum of elements in both parts is 
the same.
*/


/*
Solution:

1. Use bottom up dynamic programming.
2. This problem can be solved using dynamic programming where 
dp[i][j] = number of subsequences having product less than i 
using first j terms of the array. Which can be obtained 
by : number of subsequences using first j-1 terms + number of 
subsequences that can be formed using j-th term.
3. If the array element is greater than current product, then fill that cell with left cell's value
4. Else find the other part of product and get value of dp[other part][left cell].
5. Then add 1 to the value obtained and fill the cell with that.

Time -> O(k*m)
Time -> O(k*m)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void solve(vector<int> S, int k){
        int m = S.size();
        int dp[k+1][m+1];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<=k;i++){
            for(int j=1;j<=m;j++){
                // number of subsequence using j-1 terms
                dp[i][j] = dp[i][j-1];

                // if arr[j-1] > i it will surely make product greater
                // thus it won't contribute then
                if(S[j-1] <= i){
                    dp[i][j] += dp[i/S[j-1]][j-1] + 1;
                }
            }
        }

        
        cout<<"The answer is "<<dp[k][m]<<endl;
    }
};

int main(){
    vector<int> S = {1, 2, 3, 4};
    int k = 10;
    Solution s;
    s.solve(S, k);
}