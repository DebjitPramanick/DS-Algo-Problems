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

void sortNearlySorted(int a[], int n){
    int b[n];
    copy(a,b,n);
    insertionsort(b, n);
    display(b, n);
}

int main()
{
    int a[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(a) / sizeof(a[0]);
    sortNearlySorted(a, n);
}