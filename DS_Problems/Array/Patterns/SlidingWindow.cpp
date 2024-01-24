#include <bits/stdc++.h>
using namespace std;

// The Sliding Window algorithm is a technique used to efficiently 
// process arrays or lists in a linear manner, typically to find 
// or compute something within a fixed-size window that "slides" 
// through the array. It is useful for solving problems involving 
// substring, subarray, or subsequence manipulation.

class Solution
{
private:
    vector<int> v;

public:
    Solution(vector<int> _v)
    {
        v = _v;
    }

    void solve(int k)
    {
        int windowSize = k;
        int windowSum = 0, maxSum = 0;

        for(int i=0;i<windowSize;i++){
            windowSum+=v[i];
        }

        for(int i=windowSize;i<v.size();i++){
            windowSum+=v[i]-v[i-windowSize];
            maxSum = max(maxSum,  windowSum);
        }

        cout<<"Max sum of subarray with length k is: "<<maxSum<<endl;
    }
};

int main()
{
    Solution s({1, 3, 2, 4, 6, 2, 1});
    s.solve(3);
}