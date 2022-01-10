#include<bits/stdc++.h>
using namespace std;

// Buy and sell stocks when there must be a cooldown day between two transactions

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        //obsp:old buy state profit
        //ossp:old sell state profit
        //ocsp:old cooldown state profit
        int obsp=-prices[0];
        int ossp=0;
        int ocsp=0;
        for(int i=1;i<n;i++)
        {
            //nbsp:new buy state profit
            //nssp:new sell state profit
            //ncsp:new cooldown state profit
            int nbsp=0;
            int nssp=0;
            int ncsp=0;
            if(ocsp-prices[i]>obsp)
                nbsp=ocsp-prices[i];
            else
                nbsp=obsp;
            if(obsp+prices[i]>ossp)
                nssp=obsp+prices[i];
            else
                nssp=ossp;
            if(ocsp<ossp)
                ncsp=ossp;
            else
                ncsp=ocsp;
            ossp=nssp;
            obsp=nbsp;
            ocsp=ncsp;
        }
        return ossp;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int profit = s.maxProfit(prices);
    cout<<profit;
}
