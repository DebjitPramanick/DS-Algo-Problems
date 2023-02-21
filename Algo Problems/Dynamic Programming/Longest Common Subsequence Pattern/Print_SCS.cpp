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

class PrintSCS{
    private:
        string x = "geek", y = "eke";
    public:

        // Top-Down ---------------------------------------
        int topdown(int m, int n, string &scs){

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

            cout<<scs<<endl;

            int i = m, j = n;
            while(i>0 and j>0){
                if(x[i-1]==y[j-1]){
                    scs.push_back(x[i-1]);
                    i--;
                    j--;
                }else {
                    if(t[i][j-1]>t[i-1][j]){
                        scs.push_back(y[j-1]);
                        j--;
                    }
                    if(t[i][j-1]<t[i-1][j]){
                        scs.push_back(x[i-1]);
                        i--;
                    }
                }
                cout<<scs<<endl;
            }

            cout<<scs<<endl;

            while(i>0){
                scs.push_back(x[i-1]);
                i--;
            }
            while(j>0){
                scs.push_back(y[j-1]);
                j--;
            }

            return t[m][n];
        }

        void solve(){
            int ans;
            string scs = "";
            ans = topdown(x.size(), y.size(), scs); // Length of LCS
            // We will get the max length of scs by simply
            // merging both the strings
            // Then we will substract the length of lcs 
            // to get min length of scs
            ans = (x.size()+y.size()) - ans;
            cout<<"SCS length is: "<<ans<<endl;
            cout<<"SCS is: "<<scs<<endl;
        }

};

int main(){
    PrintSCS s;
    s.solve();
}