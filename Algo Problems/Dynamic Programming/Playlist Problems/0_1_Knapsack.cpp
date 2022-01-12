#include<bits/stdc++.h>
using namespace std;

/*
The 0/1 knapsack problem means that the items 
are either completely or no items are filled 
in a knapsack. For example, we have two items 
having weights 2kg and 3kg, respectively. If 
we pick the 2kg item then we cannot pick 1kg 
item from the 2kg item (item is not divisible); 
we have to pick the 2kg item completely.
*/

class ZeroOneKnapsack{
    private:
        vector<int> weights = {1,3,4,5};
        vector<int> values = {1,4,5,7};
        int limit = 7;
    public:

        int recur(vector<int> &w, vector<int> &v, int l, int n){
            // Base case

            if(n==0 || l==0) return 0;

            // Code for different choices

            if(w[n-1]<=l){
                // We will take the max value between the weights of
                // including the current item and excluding the current item
                return max(v[n-1]+recur(w, v, l-w[n-1], n-1), recur(w, v, l, n-1));
            }
            if(w[n-1]>l){
                return recur(w, v, l, n-1);
            }

            return 0;
        }

        void solve(){

            int maxProfit = 0;
            int n = weights.size();
            maxProfit = recur(weights, values, limit, n);
            cout<<"Max profit is: "<<maxProfit<<endl;
        }

};

int main(){
    ZeroOneKnapsack s;
    s.solve();
}