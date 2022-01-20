#include<bits/stdc++.h>
using namespace std;

/*
Given two strings. Find min number of insertions
to make string a as b.

Ex:
s1: heap
s2: pea
Ans: 1 I, 2 D
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
            int lcs;
            lcs = topdown(x.size(), y.size()); // Length of LCS
            int minD = x.size()-lcs;
            int minI = y.size()-lcs;
            cout<<"Min deletions needed: "<<minD<<endl;
            cout<<"Min insertions needed: "<<minI<<endl;
        }

};

int main(){
    LCS s;
    s.solve();
}