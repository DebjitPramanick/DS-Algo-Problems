#include <bits/stdc++.h>
using namespace std;

// Inversion Count for an array indicates – how far 
// (or close) the array is from being sorted. If the array 
// is already sorted, then the inversion count is 0, 
// but if the array is sorted in the reverse order, the 
// inversion count is the maximum. Formally speaking, two 
// elements a[i] and a[j] form an inversion if a[i] > a[j] 
// and i < j 


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

int _merge(int a[], int l, int m, int r, int temp[]){
    int i=l;
    int j=m;
    int k=l;
    int invCnt = 0;

    while(i<=m-1 and j<=r){
        if(a[i]<=a[j]) temp[k++] = a[i++];
        else{
            temp[k++] = a[j++];
            invCnt += (m-i);
        }
    }

    while(i<=m-1){
        temp[k++] = a[i++];
    }

    while(j<=r){
        temp[k++] = a[j++];
    }

    for(int p=l;p<=r;p++) a[p] = temp[p];

    return invCnt;
}

int _mergeSort(int a[], int left, int right, int temp[]){
    int mid, invCnt = 0;
    
    if(right>left){
        mid = (left+right)/2;
        invCnt+=_mergeSort(a ,left, mid, temp);
        invCnt+=_mergeSort(a ,mid+1, right, temp);
        invCnt+=_merge(a, left, mid, right, temp);
    }

    return invCnt;
}

void countInversions(int a[], int n){
    int p[n], t[n];
    copy(a, p, n);
    int ans = _mergeSort(p, 0, n-1, t);
    cout<<ans<<"  "<<endl; 
    display(p, n);
}

int main()
{
    int a[] = {8, 4, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    countInversions(a, n);
}
