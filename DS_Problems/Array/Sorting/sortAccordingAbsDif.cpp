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

void sortDiff(int a[], int n, int d){
    int b[n];
    copy(a,b,n);

    stable_sort(b, b+n, [d](int a, int b){
        if(abs(a-d)<abs(b-d)) return true;
        else return false;
    });
    
    display(b,n);
}

int main()
{
    int a[] = {10, 5, 3, 9, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int dif = 7;
    sortDiff(a, n, dif);
}