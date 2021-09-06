#include <bits/stdc++.h>
using namespace std;

// You have given an array which contain 1 to n element, 
// your task is to sort this array in an efficient way and 
// without replace with 1 to n numbers.

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

void sortOneToN(int a[], int n){ // O(nlogn)
    int b[n];
    copy(a,b,n);
    int max = 0;
    for(int i=0;i<n;i++) {
        b[i] = i+1;
    }
    
    display(b, n);
}

int main()
{
    int a[] = {10, 7, 9, 2, 8, 3, 5, 4, 6, 1};
    int n = sizeof(a) / sizeof(a[0]);
    sortOneToN(a, n);
}