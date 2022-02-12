#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> v;
    string s;

public:
    Solution(string _s)
    {
        s = _s;
    }

    void solve(vector<vector<int>> M){
        int n = M.size();
        int dp[n+2][n+2];

        memset(dp, 0, sizeof(dp));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j] = M[i-1][j-1] + max(dp[i-1][j-1], max(dp[i][j-1], dp[i+1][j-1]));
            }
        }

        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"LCS is: "<<dp[n][n]<<endl;

    }

    void display()
    {
        cout << endl;
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<vector<int>> M = {{1, 3, 3},
                             {2, 1, 4},
                             {0, 6, 4}};
    Solution s("abcde");
    s.solve(M);
    // s.display();
}
