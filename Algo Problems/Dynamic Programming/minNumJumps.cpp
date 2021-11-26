/*
Given an array of N integers arr[] where each element represents the max number 
of steps that can be made forward from that element. Find the minimum number of 
jumps to reach the end of the array (starting from the first element). If an 
element is 0, then you cannot move through that element.

Note: Return -1 if you can't reach the end of the array.
*/

/*
Solution:


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> Matrix)
    {
        int N = Matrix.size();
        int dp[N];
        for (int i = 0; i < N; i++)
            dp[i] = INT_MAX;
        
        dp[0] = 0;

        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if(dp[j]!=INT_MAX and Matrix[j]+j>=i){ // Check if j th position is reached or not and i can be reached from j
                    if(dp[j]+1 < dp[i]){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        if(dp[N-1]!=INT_MAX)
            cout << "The answer will be: " << dp[N-1] << endl; 
        else cout << "The answer will be: " << -1 << endl; 
    }
};

int main()
{
    vector<int> A{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    Solution s;
    s.solve(A);
}