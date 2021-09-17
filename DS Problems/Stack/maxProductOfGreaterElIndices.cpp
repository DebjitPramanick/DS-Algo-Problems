#include <bits/stdc++.h>
using namespace std;

// Given an array a[1..N]. For each element at 
// position i (1 <= i <= N). Where 
// 1. L(i) is defined as closest index j such that j < i and a[j] > a[i]. If no such j exists then L(i) = 0.
// 2. R(i) is defined as closest index k such that k > i and a[k] > a[i]. If no such k exists then R(i) = 0.

vector<int> getLeftGreaters(int a[], int n){
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

    return res;
}

vector<int> getRightGreaters(int a[], int n){
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

    return res;
}


void solve(int a[], int n){
    vector<int> l = getLeftGreaters(a, n);
    vector<int> r = getRightGreaters(a, n);
    int max = INT_MIN;
    
    for(int i=0;i<n;i++){
        if(max<l[i]*r[i]) max= l[i]*r[i];
    }

    cout<<"Max product is: "<<max<<endl;
}

int main()
{
    int a[] = {5, 4, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    solve(a, n);

}
