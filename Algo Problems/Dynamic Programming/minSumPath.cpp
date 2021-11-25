/*
Given a triangular structure of numbers, find the minimum path sum from top 
to bottom. Each step you may move to adjacent numbers on the row below.
*/


/*
Solution:


*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void solve(vector<vector<int> > a){
        vector<int> memo(a.size());
        int n = a.size()-1;

        for(int i=0;i<a[n].size();i++) memo[i] = a[n][i]; // For bottom row

        for(int i=a.size()-2; i>=0; i--){
            for(int j=0;j<a[i].size();j++){
                memo[j] = min(memo[j], memo[j+1]) + a[i][j];
            }
        }


        cout<<"The answer will be: "<<memo[0]<<endl;
    }
};

int main(){
    vector<vector<int> > A{ { 2 },
                            { 3, 9 },
                            { 1, 6, 7 } };
    Solution s;
    s.solve(A);
}