#include <bits/stdc++.h>
using namespace std;

// Given an array of A of n integers and an array 
// B of m integers find the Maximum Contiguous 
// Subarray Sum of array A such that any element of 
// array B is not present in that subarray.


void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void copy(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

bool isPresent(int b[], int m, int k){
    int l = 0, r = m;
    while(l<=r){
        int mid = (l+r)/2;
        if(b[mid] == k) return true;
        else if(b[mid]<k) l = mid+1;
        else r = mid-1;
    }
    return false;
}

void findSum(int a[], int b[], int n, int m){ // O((n+m)logm)
    int p[n], q[m];
    copy(a, p, n);
    copy(b, q, m);
    sort(q, q+m); // O(mlogm)
    int sum = 0, ans = INT_MIN;

    for(int i=0;i<n;i++){ // O(nlogm)
        if(!isPresent(q,m,p[i])) sum+=p[i];
        else{
            ans = max(ans, sum);
            sum = 0;
        }
    }
    ans = max(ans, sum);

    cout<<ans<<endl;

}

void findSumMap(int a[], int b[], int n, int m){ // O(max(n,m))
    int p[n], q[m];
    copy(a, p, n);
    copy(b, q, m);
    int sum = 0, ans = INT_MIN;
    map<int, int> mp;

    for(int i=0;i<m;i++) mp[q[i]]++;
    for(int i=0;i<n;i++){ // O(n)
        if(mp.find(p[i]) == mp.end()) sum+=p[i];
        else{
            ans = max(ans, sum);
            sum = 0;
        }
    }
    ans = max(ans, sum);
    cout<<ans<<endl;
}

int main()
{
    int a[] = {1, 7, -10, 6, 2};
    int b[] = {5, 6, 7, 1} ;
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    findSumMap(a, b, n, m);
}
