#include <bits/stdc++.h>
using namespace std;

/*
1. Merge Intervals
   Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
   and return an array of the non-overlapping intervals that cover all the intervals in the input.

2. Non-overlapping Intervals
   Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum 
   number of intervals you need to remove to make the rest of the intervals non-overlapping.

   Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
   Output: 1
   Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/

class Solution
{

public:
    void display(vector<vector<int>> &res)
    {
        for (auto vec : res)
        {
            for (auto x : vec)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    // static bool cmp(vector<int> a, vector<int> b){
    //     return a[1]<b[1];
    // }

    vector<vector<int>> merge() { // Merge intervals
    
        vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        vector<vector<int>> ans;

        vector<int> cur = intervals[0];
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        
        ans.push_back(cur);

        for (int i = 1; i < n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start > cur[1]) cur = intervals[i];
            else {
                ans.pop_back();
                cur[1] = end;
            }
            
            ans.push_back(cur);
        }

        display(ans);
    }

    vector<vector<int>> removeOverlapping() { // Remove overlapping intervals
    
        vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
        vector<pair<int, int>> intr;

        for (auto x : intervals) {
            intr.push_back({x[1], x[0]});
        }

        sort(intr.begin(), intr.end()); // Sort by end time

        int ans = 0, mx= -6e4;

        for (auto x: intr)
        {
            cout<<x.first<<" "<<x.second<<endl;
            if(mx <= x.second) {
                mx = x.first;
                continue;
            }
            ans++;
        }

        cout<<"#Removed intervals: "<<ans<<endl;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    sol.removeOverlapping();
}