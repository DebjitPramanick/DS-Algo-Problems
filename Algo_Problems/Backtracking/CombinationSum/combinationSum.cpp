#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
        vector<int> s;
    public: 
        Solution(vector<int> _s){
            s = _s;
        }

        void util(int i, vector<int> ans){
            if(i == s.size()){
                for(auto x: ans){
                    cout<<x<<" ";
                }
                cout<<endl;
                return;
            }
            util(i+1, ans);
            ans.push_back(s[i]);
            util(i+1,ans);
            ans.pop_back();
        }

        void solve(){
            util(0, {});
        }
        
};

int main(){
    Solution s({1,2,3});
    s.solve();
    cout<<"Hello World";
}