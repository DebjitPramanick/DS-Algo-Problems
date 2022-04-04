#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
        string str;
        
    public: 
        Solution(string _s){
            str = _s;
        }

        void util(int i, int n, string &s){
            if(i==n-1){
                cout<<s<<endl;
                return;
            }
            // Swaping characters
            // Calling child function
            // Undoing the change and going back to parent
            util(i+1, n, s);
            s.insert(i+1, "_");
            util(i+2, n+1, s);
            s.erase(i+1, 1);

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