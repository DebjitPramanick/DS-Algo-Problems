#include<bits/stdc++.h>
using namespace std;

/*
Given two strings. Find Shortest common supersequence 
from both strings.

Ex:
s1: geek
s2: eke
SCS: geeke <- Supersequence (Both s1 and s2 are present)
*/

class LCS{
    private:
        string x = "geek", y = "eke";
    public:

        // Top-Down ---------------------------------------
        int topdown(int m, int n){

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
            ans = topdown(x.size(), y.size());
            ans = (x.size()+y.size()) - ans;
            cout<<"SCS length is: "<<ans<<endl;
        }

};

int main(){
    LCS s;
    s.solve();
}