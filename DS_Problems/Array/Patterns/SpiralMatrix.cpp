#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> v;

public:
    Solution(vector<vector<int>> _v)
    {
        v = _v;
    }

    void solve()
    {
        vector<int> ans;
        int m = v.size(), n = v[0].size();
        int di = 0, x = 0, y = 0;
        vector<int> dc = {1, 0, -1, 0};
        vector<int> dr = {0, 1, 0, -1};
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for (int i = 0; i < m * n; i++)
        {
            ans.push_back(v[x][y]);
            vis[x][y] = 1;
            int newX = x + dr[di];
            int newY = y + dc[di];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !vis[newX][newY]){
                x = newX, y = newY;
            } else {
                di = (di+1)%4;
                x += dr[di];
                y += dc[di];
            }
        }
        for(auto x: ans){
            cout<<x<<" ";
        }

    }
};

int main()
{
    Solution s({{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}});
    s.solve();
}