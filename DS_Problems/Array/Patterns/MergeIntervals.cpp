#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> intervals;

public:
    Solution(vector<vector<int>> _v)
    {
        intervals = _v;
    }

    void solve()
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> cur;

        int n = intervals.size();
        cur = intervals[0];
        ans.push_back(cur);

        for (int i = 1; i < n; i++)
        {
            int end1 = cur[1];
            int end2 = intervals[i][1];

            int start1 = cur[0];
            int start2 = intervals[i][0];

            if (start2 > end1)
            {
                cur = {start2, end2};
                ans.push_back(cur);
            }
            else if (end2 > end1)
            {
                ans.pop_back();
                cur = {start1, end2};
                ans.push_back(cur);
            }
        }

        for(auto x: ans){
            cout<<"["<<x[0]<<", "<<x[1]<<"]"<<" ";
        }
    }
};

int main()
{
    Solution s({{1,3},{2,6},{8,10},{15,18}});
    s.solve();
}