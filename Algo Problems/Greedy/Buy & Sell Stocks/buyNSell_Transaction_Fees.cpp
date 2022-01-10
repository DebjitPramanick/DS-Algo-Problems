#include<bits/stdc++.h>
using namespace std;

// Buy and sell stocks with transaction fees

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int obsp=-prices[0];
        int ossp=0;
        for(int i=1;i<prices.size();i++)
        {
            int nbsp=0;
            int nssp=0;
            
            if(ossp-prices[i]>obsp)
                nbsp=ossp-prices[i];
            else
                nbsp=obsp;
            if(obsp+prices[i]-fee>ossp)
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
