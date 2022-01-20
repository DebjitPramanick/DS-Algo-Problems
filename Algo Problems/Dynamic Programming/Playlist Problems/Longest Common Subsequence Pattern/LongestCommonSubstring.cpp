#include<bits/stdc++.h>
using namespace std;

/*
Given two strings. Find longest common substring 
from both strings.

Ex:
s1: abcde
s2: abfce
LCS: ab
*/

class LCS{
    private:
        string x = "abcde", y = "abfce";
    public:

        // Top-Down ---------------------------------------
        int topdown(int m, int n){

            int ans = 0;

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
                        t[i][j] = 0;
            
                    else t[i][j] = 1+t[i-1][j-1];
                    ans = max(ans, t[i][j]);
                }
            }

            return ans;
        }

        void solve(){
            int ans;
            ans = topdown(x.size(), y.size());
            cout<<"Longest common substring length is: "<<ans<<endl;
        }

};

int main(){
    LCS s;
    s.solve();
}