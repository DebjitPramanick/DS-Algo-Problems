/*
Given a string str, find the length of the longest repeating 
subsequence such that it can be found twice in the given string. 
The two identified subsequences A and B can use the same ith 
character from string str if and only if that ith character 
has different indices in A and B.
*/


/*
Solution:

1. Use bottom up dynamic programming.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(string s){
        s = ' '+s;
        int m = s.size();
        int dp[m][m];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<m;i++){
            for(int j=1;j<m;j++){
                // If characters match and indexes are not same
                if(s[i]==s[j] && i!=j) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout<<"The answer is "<<dp[m-1][m-1]<<endl;

    }
};

int main(){
    string str = "axxxmn";
    Solution s;
    s.solve(str);
}