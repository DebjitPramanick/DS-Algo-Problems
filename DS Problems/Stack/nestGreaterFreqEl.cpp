#include <bits/stdc++.h>
using namespace std;

// Given an array, for each element find the value of the nearest 
// element to the right which is having a frequency greater than as 
// that of the current element. If there does not exist an answer for 
// a position, then make the value ‘-1’. 

void solve(int a[], int n){
    stack<int> st;
    map<int, int> mp;

    for(int i =0;i<n;i++){
        mp[a[i]]++;
    }

    st.push(a[0]);
    for(int i=1;i<n;i++){
        if(st.empty()){
            st.push(a[i]);
            continue;
        }

        while(!st.empty() and mp[st.top()]<mp[a[i]]){
            cout<<st.top()<<"-->"<<a[i]<<endl;
            st.pop();
        }

        st.push(a[i]);
    }

    while(!st.empty()){
        cout<<st.top()<<"-->"<<"-1"<<endl;
        st.pop();
    }
    
};

int main(){
    int a[] = {1, 1, 2, 3, 4, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    solve(a, n);
    return 0;
}
