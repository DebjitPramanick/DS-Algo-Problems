#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> v;
    string s;

public:
    Solution(vector<int> _v)
    {
        v = _v;
    }

    int search(int k, int s, int e){
        while(s<e){
            int mid = (s+e)/2;
            if(v[mid] == k) return mid;
            else if(v[mid]<k) s = mid+1;
            else e = mid-1;
        }
        return -1;
    }

    void solve(int k){
        for(int i=0;i<v.size()-1;i++){
            int cur = v[i];
            int j = i-1;
            while(v[j]>cur and j>=j-k and j>=0){
                v[j+1] = v[j];
                j--;
            }
            v[j+1] = cur;
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
    vector<int> M = {10, -10, 20, -40};
    Solution s(M);
    s.solve(3);
    // s.display();
}
