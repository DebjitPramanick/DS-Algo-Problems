/*
Given an integer N denoting the Length of a line segment. 
You need to cut the line segment in such a way that the 
cut length of a line segment each time is either x , y 
or z. Here x, y, and z are integers.
After performing all the cut operations, your total number 
of cut segments must be maximum.
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

    void solve(int N, int x, int y, int z){
        vector<int> segs;
        segs.push_back(x), segs.push_back(y), segs.push_back(z);
        vector<int> dp(N+1,0);

        for(int j=0;j<segs.size();j++){
            for(int i=1;i<=N; i++){
                //we will update dp[i] if the point is x,y,z or if the
                //points are visited by some combination of x,y,z.
                if(i==segs[j] or (i>segs[j] and dp[i-segs[j]]>0))
                    dp[i]=max(dp[i-segs[j]]+1,dp[i]);
            }
        }

        cout<<"The answer will be: "<<dp[N]<<endl;
    }
};

int main(){
    Solution s;
    int x = 1, y = 1, z = 2;
    s.solve(4, x, y, z);
}