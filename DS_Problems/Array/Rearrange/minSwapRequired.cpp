#include <bits/stdc++.h>
using namespace std;

// Given an array of n positive integers and a number k. 
// Find the minimum number of swaps required to bring all 
// the numbers less than or equal to k together. 

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

int findMinSwap(int a[], int n, int k){
    int b[n];
    copy(a, b, n);
    int cnt = 0, bad = 0;
    for(int i=0;i<n;i++) if(b[i]<=k) cnt++;
    for(int i=0;i<cnt;i++) if(b[i]>k) bad++;
    int ans = bad;

    // Sliding window method
    int i = 0;
    int j = cnt;
    while(j<n){
        if(a[i]>k) --bad;
        if(a[j]>k) ++bad;
        ans = min(ans, bad);
        i++,j++;
    }
    return ans;
}

int main()
{
    int a[] = {2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    int res = findMinSwap(a, n, k);
    cout<<"Minimum swaps required: "<<res;
}
