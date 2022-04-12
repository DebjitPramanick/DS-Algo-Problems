#include <bits/stdc++.h>
using namespace std;

// Given a target sum. Find subsets with that sum.

class Solution{
    private: 
        vector<int> s;
        int sum;
    public: 
        Solution(vector<int> _s, int _sum){
            s = _s;
            sum = _sum;
        }

        void util(int i, vector<int> ans, int cursum){
            if(cursum == sum){
                for(auto x: ans){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
            if(cursum >sum || i == s.size()) return;

            util(i+1, ans, cursum);
            ans.push_back(s[i]);
            util(i+1,ans, cursum+s[i]);
            ans.pop_back();
        }

        void solve(){
            util(0, {}, 0);
        }
        
};

int main(){
    Solution s({1, 1, 2, 3}, 4);
    s.solve();
    cout<<"Hello World";
}