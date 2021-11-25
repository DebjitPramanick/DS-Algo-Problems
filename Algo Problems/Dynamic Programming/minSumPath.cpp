/*
Given a triangular structure of numbers, find the minimum path sum from top 
to bottom. Each step you may move to adjacent numbers on the row below.
*/


/*
Solution:

As the solution for a maximum number of cuts that can be made 
in a given length depends on the maximum number of cuts previously 
made in shorter lengths, this question could be solved by the 
approach of Dynamic Programming. Suppose we are given a length 
'l'. For finding the maximum number of cuts that can be made in 
length 'l', find the number of cuts made in shorter previous 
length 'l-p', 'l-q', 'l-r' lengths respectively. The required 
answer would be the max(l-p,l-q,l-r)+1 as one more cut should be 
needed after this to cut length 'l'. So for solving this problem 
for a given length, find the maximum number of cuts that can be made 
in lengths ranging from '1' to 'l'. 

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