#include<bits/stdc++.h>
using namespace std;

/*
Buy and sell stocks with transaction fees

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of 
the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
*/

class Solution {
public:

    int recMaxProfit(vector<int>& prices, int idx, int buy) {

        if(idx>=prices.size()) {
            return 0;
        }

        int profit = 0;
        if(buy) { // When buying
            profit = max(recMaxProfit(prices, idx+1, 0)-prices[idx], recMaxProfit(prices, idx+1, 1));
        } else { // When selling
            profit = max(recMaxProfit(prices, idx+1, 1)+prices[idx], recMaxProfit(prices, idx+1, 0));
        }

        return profit;
    }

    int dpMaxProfit(vector<int>& prices) {

        int n = prices.size();

        int dp[n+1][2];

        for(int i=0;i<=n;i++)
            for(int j=0;j<2;j++) dp[i][j] = 0;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++) {
                int profit = 0;
                if(j == 1) {
                    profit = max(dp[i+1][0]-prices[i], dp[i+1][1]);
                } else {
                    profit = max(dp[i+1][1]+prices[i], dp[i+1][0]);
                }

                dp[i][j] = profit;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int profit = s.maxProfit(prices);
    int recProfit = s.recMaxProfit(prices, 0, 1);
    int dpProfit = s.dpMaxProfit(prices);
    cout<<profit<<" "<<recProfit<<" "<<dpProfit;
}
