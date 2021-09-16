#include <bits/stdc++.h>
using namespace std;
// The stock span problem is a financial problem 
// where we have a series of n daily price quotes 
// for a stock and we need to calculate span of 
// stock’s price for all n days. The span Si of 
// the stock’s price on a given day i is defined 
// as the maximum number of consecutive days just 
// before the given day, for which the price of the 
// stock on the current day is less than or equal 
// to its price on the given day. For example, if 
// an array of 7 days prices is given as 
// {100, 80, 60, 70, 60, 75, 85}, then the span 
// values for corresponding 7 days are 
// {1, 1, 1, 2, 1, 4, 6} 

class Solution
{
    stack<string> s;
    
    public:

    void solve(int n, int prices[]) // O(n) [Time] O(n) [Space, Worst Case]
    {
        stack<int> s;
        int S[n];
        s.push(0);
        S[0] = 1;

        for(int i=1;i<n;i++){
            while(!s.empty() and prices[s.top()]<=prices[i]) s.pop();
            S[i] = s.empty() ? i+1 : i-s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++){
            cout<<"Span["<<i<<"] = "<<S[i]<<endl;
        }
    }
};

int main()
{
    Solution s;
    int prices[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(prices) / sizeof(prices[0]);
    s.solve(n, prices);
}