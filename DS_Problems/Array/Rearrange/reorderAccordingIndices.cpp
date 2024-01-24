#include <bits/stdc++.h>
using namespace std;

// Given two integer arrays of same size, “arr[]” and “index[]”, 
// reorder elements in “arr[]” according to given index array. 
// It is not allowed to given array arr’s length.

/// O(nlogn) Time O(0) space

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

void reorder(int a[], int indices[], int n){
    int b[n], ind[n];
    copy(a, b, n);
    copy(indices, ind, n);
    
    for(int i=0;i<n;i++){
        while(ind[i]!=i){

            // Storing old values
            int oldIdx = ind[ind[i]];
            int oldVal = b[ind[i]];

            // Replacing old values with current values
            b[ind[i]] = b[i];
            ind[ind[i]] = ind[i];

            // Replacing current values with old values
            ind[i] = oldIdx;
            b[i] = oldVal;
        }
    }
    display(b,n);
    display(ind,n);
}

int main(){
    int a[] = {50, 40, 70, 60, 90};
    int ind[] = {3,  0,  4,  1,  2};
    int n = sizeof(a) / sizeof(a[0]);
    reorder(a, ind, n);
}

// 0  1  2
// 10 11 12
// 1  0  2

// oldIdx = 0
// oldVal = 11