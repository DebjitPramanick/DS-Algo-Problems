#include<bits/stdc++.h>
using namespace std;

// Find k closest number of x

typedef pair<int, int> pi; 

class Solution{

    vector<int> v = {5, 6, 7, 8, 9};
    int n = v.size();
    int k = 3;
    int x = 7;

    public:

    void find(){
        priority_queue<pi> pq; // max-heap

        for(int i=0;i<n;i++){
            int dif = abs(v[i]-x);
            pq.push({dif, v[i]}); // Sorting will be applied on the difference value
            if(pq.size()>k) pq.pop();
        }
        cout<<"K th closest element: "<<pq.top().second<<endl;
    }
};

int main(){
    Solution s;
    s.find();
}