/*
Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.
*/

/*
Solution:


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> Matrix)
    {
        int N = Matrix.size();
        int dp[N][N];
        for (int i = 0; i < N; i++)
            dp[0][i] = Matrix[0][i];

        // calculating the path sums of the matrix
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j == 0 && j + 1 < N)
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);
                else if (j - 1 >= 0 && j == N - 1)
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
                else if (j > 0 && j + 1 < N)
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1]));
                else
                    dp[i][j] = Matrix[i][j] + dp[i - 1][j];
            }
        }

        // getting the maximum path sum
        int maxi = 0;
        for (int i = 0; i < N; i++)
            maxi = max(maxi, dp[N - 1][i]);

        cout << "The answer will be: " << maxi << endl;
    }
};

int main()
{
    vector<vector<int>> A{{348, 391},
                          {618, 193}};
    Solution s;
    s.solve(A);
}