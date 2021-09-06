#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array of integers, sort the array 
// into a wave like array. An array ‘arr[0..n-1]’ is sorted in 
// wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

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

void sortInWave(int a[], int n){ // O(nlogn)
    int b[n];
    copy(a,b,n);
    insertionsort(b, n);
    for(int i=0;i<n-1;i+=2){
        swap(b[i], b[i+1]);
    }
    display(b, n);
}

void sortInWaveSingle(int a[], int n){
    int b[n];
    copy(a,b,n);

    for(int i=0;i<n;i+=2){
        if(i>0 and b[i]<b[i-1]) swap(b[i], b[i-1]);
        if(i<n-1 and b[i]<b[i+1]) swap(b[i], b[i+1]);
    }

    display(b, n);
}

int main()
{
    int a[] = {10, 5, 6, 3, 2, 20, 100, 80};
    int n = sizeof(a) / sizeof(a[0]);
    sortInWaveSingle(a, n);
}