#include <bits/stdc++.h>
using namespace std;


class Solution
{

public:
    void display(<vector<int> &res)
    {
        for (auto el : res) cout << el << " ";
        cout << endl;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int di = 0, x = 0, y = 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };
        
        for(int i=0;i<m*n;i++){
            ans.push_back(matrix[x][y]);
            vis[x][y] = 1;
            int newX = x+dr[di];
            int newY = y+dc[di];
            
            if(newX >= 0 && newX < m && newY >= 0 && newY<n && !vis[newX][newY]) {
                x = newX;
                y = newY;
            } else {
                di = (di+1)%4;
                x += dr[di];
                y += dc[di];
            }
        }
        
        return ans;
    }

    
};

int main()
{
    Solution sol;

    vector<int> ans = sol.spiralOrder();

    sol.display(ans);
}