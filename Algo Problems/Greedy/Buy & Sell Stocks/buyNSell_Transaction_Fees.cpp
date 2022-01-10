#include<bits/stdc++.h>
using namespace std;

// Buy and sell stocks with transaction fees
// Explanation: Pepcoding

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int obsp=-prices[0]; // Old buy state
        int ossp=0; // Old sell state
        for(int i=1;i<prices.size();i++)
        {
            int nbsp=0; // New buy state
            int nssp=0; // New sell state
            
            if(ossp-prices[i]>obsp)
                /* 
                   If new buy state is better than the old buy state
                   with the profit of old sell state
                */
                nbsp=ossp-prices[i];
            else
                nbsp=obsp; // Else make new buy state as old buy state
            if(obsp+prices[i]-fee>ossp) 
                /* 
                   If new sell state (profit for selling stocks - fees) 
                   is better than the old sell state
                */
                nssp=obsp+prices[i]-fee;
            else
                nssp=ossp;
            ossp=nssp;
            obsp=nbsp;
        }
        if(ossp<0)
            return 0;
        else
        return ossp;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int profit = s.maxProfit(prices, 10);
    cout<<profit;
}
