#include<bits/stdc++.h>
using namespace std;

// Buy and sell stocks when only one transaction is possible

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
