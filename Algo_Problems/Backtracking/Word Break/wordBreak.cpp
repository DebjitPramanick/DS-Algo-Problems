#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
        string s;
        vector<string> words;
    public: 
        Solution(string _s, vector<string> _words){
            s = _s;
            words = _words;
        }

        bool findWord(string w){
            for(auto x: words) if(w==x) return true;
            return false;
        }

        void util(string ans, string target){
            if(target.size() == 0) {
                cout<<ans<<endl;
                return;
            }

            for(int i=0;i<target.size();i++){
                string left = target.substr(0, i+1);
                if(findWord(left)){
                    string right = target.substr(i+1, target.size());
                    util(ans+left+" ", right);
                }
            }

            
        }

        void solve(){
            util("", s);
        }
        
};

int main(){
    Solution s("Iamaboy", {"I", "boy", "am", "a", "aboy", "Iam"});
    cout<<"Hello World"<<endl;
    s.solve();
}