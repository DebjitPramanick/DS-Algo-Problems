#include<bits/stdc++.h>
using namespace std;

/*
Given one string. Find length of longest number 
pallindromic subsequence

Ex:
s: agbcba
Ans: abcba (5)
*/

class LCS{
    private:
        string x = "agbcba";
    public:

        // Top-Down ---------------------------------------
        int topdown(int m, int n, string y){

            // Base case
            int t[m+1][n+1];
            for(int i=0;i<m+1;i++){
                for(int j=0;j<n+1;j++){
                    if(i==0 || j==0) t[i][j] = 0;
                }
            }

            // Code for different choices
            for(int i=1;i<m+1;i++){
                for(int j=1;j<n+1;j++){
                    if(x[i-1]!=y[j-1]) 
                        t[i][j] = max(t[i-1][j], t[i][j-1]);
            
                    else t[i][j] = 1+t[i-1][j-1];
                }
            }

            return t[m][n];
        }

        void solve(){
            int ans;
            string rev = x;
            reverse(rev.begin(), rev.end()); // Get second string by reversing the given string
            ans = topdown(x.size(), rev.size(), rev);
            cout<<"LPS length is: "<<ans<<endl;
        }

};

int main(){
    LCS s;
    s.solve();
}