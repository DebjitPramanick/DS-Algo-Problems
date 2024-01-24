#include <bits/stdc++.h>
using namespace std;

// Given an array of integers, print the array in such a way 
// that the first element is first maximum and second element 
// is first minimum and so on.

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

void insertionsort(int a[], int n){
    for(int i=0;i<n;i++){
        int cur = a[i];
        int j = i-1;
        while(a[j]>cur && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cur;
    }
}

void altSort(int a[], int n){
    int b[n];
    copy(a,b,n);
    insertionsort(b, n);
    display(b, n);
    int l = 0, r = n-1;
    while(l<r){
        cout<<b[r]<<" "<<b[l]<<" "<<" ";
        l++, r--;
    }

    if (n % 2 != 0)
        cout << b[l];
}

int main()
{
    int a[] = {7, 1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    altSort(a, n);
}
