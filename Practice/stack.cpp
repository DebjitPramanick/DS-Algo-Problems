#include <bits/stdc++.h>
using namespace std;

class Solution{
    private: 
        
    public: 
        Solution(){

        }

        vector<int> getLeft(vector<int> a){
            int n = a.size();
            vector<int> res(n+1, 0);
            stack<int> s;

            for(int i=n-1;i>=0;i--){
                while(!s.empty() and a[i]>a[s.top()-1]){
                    int r = s.top();
                    s.pop();
                    res[r-1] = i+1;
                }
                s.push(i+1);
            }

            for(auto it: res) cout<<it<<" "<<" ";
            cout<<endl;
            return res;
        }

        vector<int> getRight(vector<int> a){
            int n = a.size();
            vector<int> res(n+1, 0);
            stack<int> s;

            for(int i=0;i<n;i++){
                while(!s.empty() and a[s.top()-1]<a[i]){
                    int r = s.top();
                    s.pop();
                    res[r-1] = i+1;
                }
                s.push(i+1);
            }

            for(auto it: res) cout<<it<<" "<<" ";
            cout<<endl;
            return res;
        }

        void solve(vector<int> v){
            vector<int> l = getLeft(v);
            vector<int> r = getRight(v);


            
        }

        
};

int main(){
    Solution s;
    s.solve({5, 4, 3, 4, 5});
}