#include <bits/stdc++.h>
using namespace std;

// Given an array, print the Next Greater Element (NGE) 
// for every element. The Next greater Element for an 
// element x is the first greater element on the right 
// side of x in the array. Elements for which no greater 
// element exist, consider the next greater element as -1. 

void solve(int a[], int n){
    stack<int> st;
    st.push(a[0]);
    for(int i=1;i<n;i++){
        if(st.empty()) {
            st.push(a[i]);
            continue;
        }
        while(!st.empty() and st.top() < a[i]){
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
    int a[] = {4, 5, 2, 25};
    int n = sizeof(a)/sizeof(a[0]);
    solve(a, n);
    return 0;
}
