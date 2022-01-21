#include<bits/stdc++.h>
using namespace std;

/*
Given one string. We have to delete some 
characters from string to make this palindrome

Ex:
s: agbcba
Ans: abcba (1 D)
*/

class MinNumDeletions{
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
            int minD = x.size()-ans;
            cout<<"Min num of deletions is: "<<minD<<endl;
        }

};

int main(){
    MinNumDeletions s;
    s.solve();
}