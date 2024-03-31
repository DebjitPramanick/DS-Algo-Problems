#include<bits/stdc++.h>
using namespace std;

/*
Given an array p[] which represents the chain of matrices 
such that the ith matrix Ai is of dimension p[i-1] x p[i]. 
We need to write a function MatrixChainOrder() that should 
return the minimum number of multiplications needed to 
multiply the chain. 

Ex:
a: {40, 20, 30, 10, 30}
Output: 26000
*/


int static dp[1002][1002];
class MCM{
    private:
        string s = "nitik";
    public:

        bool isPalindrome(string &str, int i, int j){
            while(i < j)
            {
              if(str[i] != str[j])
                return false; 
              i++;
              j--;
            }
            return true;
        }

        // Recursion ---------------------------------------
        int rec(string &str, int i, int j){

            // Base case
            if(i>=j) return 0;
            if(isPalindrome(str, i, j)) return 0;

            // Code for different choices
            int mn = INT_MAX;
            for(int k=i;k<=j-1;k++){
                int temp = rec(str, i, k) + rec(str, k+1, j) + 1;
                mn = min(mn, temp);
            }
            return mn;
        }

        // Recursion ---------------------------------------
        int memoization(string &str, int i, int j){

            // Base case
            if(i>=j) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            if(isPalindrome(str, i, j)) return 0;

            // Code for different choices
            int mn = INT_MAX;
            for(int k=i;k<=j-1;k++){
                int left, right;

                if(dp[i][k]!=-1) left = dp[i][k];
                else left = memoization(str, i, k);

                if(dp[k+1][j]!=-1) right = dp[k+1][j];
                else right = memoization(str, k+1, j);
                int temp = left + right + 1;
                mn = min(mn, temp);
            }
            return dp[i][j] = mn;
        }

        void solve(){
            int ans;
            ans = rec(s, 0, s.size()-1);
            cout<<"Min partitioning is: "<<ans<<endl;
            ans = memoization(s, 0, s.size()-1);
            cout<<"Min partitioning is: "<<ans<<endl;
        }

};

int main(){
    MCM s;
    memset(dp, -1, sizeof(dp));
    s.solve();
}