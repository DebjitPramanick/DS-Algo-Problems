#include<bits/stdc++.h>
using namespace std;

// k-th smallest element
// k-th largest element

class Solution{

    vector<int> v = {7, 10, 4, 3, 20, 15};
    int n = v.size();
    int k = 2;

    public:

    /*
    1. Use max-heap to find smallest element
    2. Use min-heap to find largest element
    */

    void findKthSmallest(){
        priority_queue<int> pq; // max-heap
        for(int i=0;i<n;i++){
            pq.push(v[i]);
            if(pq.size()>k) pq.pop();
        }
        cout<<"K th smallest element: "<<pq.top()<<endl;
    }

    void findKthLargest(){
        priority_queue<int, vector<int>, greater<int>> pq; // max-heap
        for(int i=0;i<n;i++){
            pq.push(v[i]);
            if(pq.size()>k) pq.pop();
        }
        cout<<"K th largest element: "<<pq.top()<<endl;
    }
};

int main(){
    Solution s;
    s.findKthSmallest();
    s.findKthLargest();
}