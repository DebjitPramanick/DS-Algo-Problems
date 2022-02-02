#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> v;

public:
    Solution(vector<int> _v)
    {
        v = _v;
    }

    void solve(int k)
    {
        int s = 0, e = v.size()-1;
        int f = 0;

        while(s<=e){
            int mid = (s+e)/2;
            if(v[mid]<v[(mid+1)%n] && v[mid]>v[mid-1]) {
                cout<<"Rotation count: "<<mid<<endl;
                f = 1;
                break;
            }
            else if(v[mid]>v[mid+1]){
                if(v[s]>k) s = mid+1;
                else e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        if(!f) cout<<"Not found."<<endl;
        
    }

    void display()
    {
        cout << endl;
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s({5, 8, 9, 1, 3, 4});
    s.solve(5);
    s.display();
}