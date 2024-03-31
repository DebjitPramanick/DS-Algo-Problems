#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of Denominations and a value X. You
need to find the min number of coins required to make 
value X.

Note: We have infinite supply of each coin.
*/

int main(){
    vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int target = 54;

    int ans = 0;
    sort(coins.begin(), coins.end(), greater<int> ());

    for(int i=0;i<coins.size();i++){
        ans+=target/coins[i];
        target-=(target/coins[i])*coins[i];
    }

    cout<<"Min coins required: "<<ans<<endl;

}