#include <bits/stdc++.h>
using namespace std;

// Given an array of 0s and 1s in random order. Segregate 0s on left 
// side and 1s on right side of the array. Traverse array only once.

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

void sortOneZero(int a[], int n){ // O(nlogn)
    int b[n];
    copy(a,b,n);
    int l = 0, r = n-1;

    for(int i=0;i<n;i++) {
        if(b[l]==0) l++;
        else{
            swap(b[l], b[r]);
            r--;
        }
    }
    
    display(b, n);
}

int main()
{
    int a[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    sortOneZero(a, n);
}