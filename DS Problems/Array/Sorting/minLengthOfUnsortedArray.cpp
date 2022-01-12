#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array arr[0..n-1] of size n, 
// find the minimum length subarray arr[s..e] 
// such that sorting this subarray makes the whole 
// array sorted. 

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

bool checkIfSorted(int a[], int n){
    for(int i=0;i<n-1;i++)
        if(a[i+1]<a[i]) return false;
    return true;
}

void findMinLength(int a[], int n)
{
    int p[n];
    copy(a, p, n);
    int s, e;
    
    if(checkIfSorted(p, n)){
        cout<<"Array is sorted.";
    }
    else{
        for(int i=0;i<n-1;i++){
            if(p[i]>p[i+1]){
                s = i;
                break;
            }
        }

        for(int i=n-1;i>0;i--){
            if(p[i]<p[i-1]){
                e = i;
                break;
            }
        }

        int mx = p[s], mn = p[s];
        for(int i=s+1;i<=e;i++){
            if(mx<p[i]) mx = p[i];
            if(mn>p[i]) mn = p[i];
        }

        for(int i=0;i<s;i++){
            if(mn<p[i]) {
                s = i;
                break;
            }
        }

        for(int i=n-1;i>e;i--){
            if(mx>p[i]) {
                e = i;
                break;
            }
        }

        cout << s << " and " << e;
    }
}

int main()
{
    int a[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n = sizeof(a) / sizeof(a[0]);
    findMinLength(a, n);
}
