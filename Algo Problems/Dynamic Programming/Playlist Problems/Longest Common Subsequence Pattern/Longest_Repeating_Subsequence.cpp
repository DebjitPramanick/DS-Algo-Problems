#include<bits/stdc++.h>
using namespace std;

/*
Given a string. Find longest repeating subsequence.

Ex:
s: aabebcdd
LRS: abd
*/

class LRS{
    private:
        string x = "aabebcdd";
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
                    if(x[i-1]==x[j-1] && i!=j) 
                        t[i][j] = 1+t[i-1][j-1];
            
                    else t[i][j] = max(t[i][j-1], t[i-1][j]);;
                    ans = max(ans, t[i][j]);
                }
            }

            return ans;
        }

        void solve(){
            int ans;
            ans = topdown(x.size(), x.size());
            cout<<"Longest repeating subsequence length is: "<<ans<<endl;
        }

};

int main(){
    LRS s;
    s.solve();
}