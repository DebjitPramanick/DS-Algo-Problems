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
        string s = "abcde";
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

        void solve(){
            int ans;
            ans = rec(s, 0, s.size()-1);
            cout<<"Min partitioning is: "<<ans<<endl;
        }

};

int main(){
    MCM s;
    memset(dp, -1, sizeof(dp));
    s.solve();
}