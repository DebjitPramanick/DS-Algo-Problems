#include <bits/stdc++.h>
using namespace std;

// The Kadane's algorithm, also known as the Maximum Subarray Sum algorithm,
// is a popular algorithm for finding the maximum sum of a contiguous subarray
// within an array of numbers.

class Solution
{
private:
    vector<int> v;

public:
    Solution(vector<int> _v)
    {
        v = _v;
    }

    void solve()
    {
        int max_so_far = INT_MIN; // Initialize max_so_far to the smallest possible integer
        int max_ending_here = 0;  // Initialize max_ending_here to 0
        vector<int> ans;

        for (int i = 0; i <
         v.size(); i++)
        {
            max_ending_here = max(v[i], max_ending_here + v[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }

        cout<<"Max subarray sum is: "<<max_so_far<<endl;
    }
};

int main()
{
    Solution s({-2, -3, 4, -1, -2, 1, 5, -3});
    s.solve();
}