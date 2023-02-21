#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array height of length n. There are n 
vertical lines drawn such that the two endpoints of the ith line 
are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, 
such that the container contains the most water.

Return the maximum amount of water a container can store.
*/

class Solution {

    public: 

    int maxArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        int s = 0, e = n-1;

        while(s<e){
            
            if(heights[e]>=heights[s]){
                int area = heights[s] * (e-s);
                maxArea = max(maxArea, area);
                s++;
            }
            else if(heights[e]<=heights[s]){
                int area = heights[e] * (e-s);
                maxArea = max(maxArea, area);
                e--;
            }
        }

        return maxArea;
    }
};

int main () {
    Solution sol;

    vector<int> heights = {1,8,6,2,5,4,8,3,7};

    int ans = sol.maxArea(heights);

    cout<<"Answer is: "<<ans<<endl;
}