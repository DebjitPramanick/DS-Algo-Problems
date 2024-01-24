#include <bits/stdc++.h>
using namespace std;

// Given an array of n numbers. The problem is to move all 
// the 0’s to the end of the array while maintaining the 
// order of the other elements. Only single traversal of 
// the array is required.

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

void rearrangeArr(int a[], int n)
{
    int b[n];
    copy(a, b, n);

    int count = 0; 

    for(int i=0;i<n-1;i++){
        if(b[i]!=0){
            swap(b[count++], b[i]);
        }
    } 
    

    display(b, n);
}

int main()
{
    int a[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(a) / sizeof(a[0]);
    rearrangeArr(a, n);
}