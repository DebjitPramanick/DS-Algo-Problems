#include <bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=VB0b6XQUHMk&list=PLNxqWc8Uj2LTaaxs-8vzK0Ft47rMggFnN&index=6
typedef vector<vector<int>> vvi;
class Solution{
    private: 
        vvi m;
        
    public: 
        Solution(vvi _v){
            m = _v;
        }

        bool isSafe(int row, int col, int n){
            if((row>=0 && row<=n-1) && (col>=0 && col<=n-1) && m[row][col] != 0) return true;
            return false; 
        }

        void util(int row, int col, int n, string &s){
            if(row==n-1 && col==n-1){
                cout<<s<<endl;
                return;
            }
            // Swaping characters
            // Calling child function
            // Undoing the change and going back to parent
            vector<int> rowOpts = {1,0,-1,0};
            vector<int> colOpts = {0,1,0,-1};
            vector<char> dirOpt = {'R', 'D', 'L', 'U'};

            for(int i=0;i<n;i++){
                if(isSafe(row+rowOpts[i], col+colOpts[i], n)){
                    m[row][col] = 0;
                    s.push_back(dirOpt[i]);
                    util(row+rowOpts[i], col+colOpts[i], n, s);
                    m[row][col] = 1;
                    s.pop_back();
                }
            }

        }

        void solve(){
            string ans = "";
            util(0,0,m.size(),ans);
        }
        
};

int main(){
    Solution s({{1,1,0}, {1,1,1}, {0,0,1}});
    cout<<"Hello World"<<endl;
    s.solve();
}