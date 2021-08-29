#include <bits/stdc++.h>
using namespace std;

// Given an array of positive and negative numbers,
// arrange them such that all negative integers appear
// before all the positive integers in the array
// without using any additional data structure like hash
// table, arrays, etc. The order of appearance should
// be maintained.

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

void checkPair(int a[], int n, int x){
    int b[n];
    copy(a,b,n);
    sort(b,b+n);
    int p=0, q=n-1;
    while (p<=q)
    {
        if(b[p]+b[q] == x) {
            cout<<b[p]<<"  "<<b[q]<<endl;
            break;
        }
        else if(b[p]+b[q]<x) p++;
        else q--;
    }
    
}

int main()
{
    int a[] = {0, -1, 2, -3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int x = -2;
    checkPair(a, n, x);
}
