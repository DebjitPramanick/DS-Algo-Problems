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

    void solve(vector<int> ind){
        
        int n = v.size();
        for(int i=0;i<n;i++){
            while(ind[i]!=i){
                int oX = ind[ind[i]];
                int oV = v[ind[i]];

                ind[ind[i]] = ind[i];
                v[ind[i]] = v[i];

                v[i] = oV;
                ind[i] = oX;
            }
        }
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
    Solution s({50, 40, 70, 60, 90});
    s.solve({3,  0,  4,  1,  2});
    s.display();
}

/*

curIdx = 0
curEl = 50

oldIdx = ind[ind[i]] = 1
oldVal = v[ind[i]] = 60

newIdx = 


*/
