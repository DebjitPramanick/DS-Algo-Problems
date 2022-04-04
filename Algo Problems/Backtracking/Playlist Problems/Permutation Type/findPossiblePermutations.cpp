#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
        string str;
        
    public: 
        Solution(string _s){
            str = _s;
        }

        void util(int i, int n, string s){
            if(i==n){
                cout<<s<<endl;
                return;
            }
            // Swaping characters
            // Calling child function
            // Undoing the change and going back to parent
            for(int j=i;j<n;j++){
                swap(s[j], s[i]);
                util(i+1, n, s);
                swap(s[j], s[i]);
            }

        }

        void solve(){
            util(0, str.size(), str);
        }
        
};

int main(){
    Solution s("abc");
    cout<<"Hello World"<<endl;
    s.solve();
}