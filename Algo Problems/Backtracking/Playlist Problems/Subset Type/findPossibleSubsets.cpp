#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> v = {};

    public:
    Solution(vector<int> _v){
        v = _v;
    }
    
    void util(int i, int n, set<vector<int>> &s, vector<int> &subs){
        if(i==n){
            s.insert(subs);
            return;
        }
        util(i+1, n, s, subs);
        subs.push_back(v[i]);
        util(i+1, n, s, subs);
        subs.pop_back();
    }

    void solve(){
        set<vector<int>> s;
        vector<int> subs;
        int n = v.size();
        util(0, n, s, subs);
        for(auto it: s) {
            for(auto x: it){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

};

int main(){
    Solution s({1, 2, 3});
    s.solve();
}