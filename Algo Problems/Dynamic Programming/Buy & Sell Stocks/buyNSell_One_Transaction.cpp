#include<bits/stdc++.h>
using namespace std;

/*
Buy and sell stocks when only one transaction is possible

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock. Return the maximum profit you can achieve 
from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int cp=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            cp=min(cp,prices[i]);
            profit=max(profit,prices[i]-cp);
        }
        return profit;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int profit = s.maxProfit(prices);
    cout<<profit;
}
