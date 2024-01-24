#include<bits/stdc++.h>
using namespace std;

// Sort k-sorted array

class Solution{

    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int n = v.size();
    int k = 3;

    public:

    void sortArray(){
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        vector<int> ans;
        for(int i=0;i<n;i++){
            pq.push(v[i]);
            if(pq.size()>k) {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        while(pq.size()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        for(auto it: ans){
            cout<<it<<"  ";
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    s.sortArray();
}