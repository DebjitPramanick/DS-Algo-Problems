#include <bits/stdc++.h>
using namespace std;

/*
We are given n items with {weight: value} of each item and the
capacity of knapsack 'W'. We need to put these items in knapsack
such that final value of items in knapsack is maximum.
*/

bool cmp(vector<int> a, vector<int> b){
    double m = (double) a[1]/a[0];
    double n = (double) b[1]/b[0];
    // We will find price of uint weight

    return m>n;
}

int main(){
    vector<vector<int>> items = {{5, 40}, {4, 24}, {6, 30}, {7, 21}, {6, 12}};
    int tW = 20;

    sort(items.begin(), items.end(), cmp);

    int ans = 0;
    for(int i=0;i<items.size();i++){
        if(tW >= items[i][0]){
            ans += items[i][1];
            tW -= items[i][0];
            continue;
        }
        double uw = (double) items[i][1]/items[i][0]; // Find unit weight
        ans += uw*tW; // Get price of partial item and add
        tW = 0;
        break;
    }

    cout<<"Max profit: "<<ans<<endl;

}