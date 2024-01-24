#include <bits/stdc++.h>
using namespace std;

// Given an array of n elements. Our task is to 
// write a program to rearrange the array such 
// that elements at even positions are greater 
// than all elements before it and elements at 
// odd positions are less than all elements before it.


void display(int a[], int n){
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void copy(int a[], int b[], int n){
    for (int i = 0; i < n; i++) b[i] = a[i];
}

void rearrangeArr(int a[], int n){ // O(n)
    int b[n], c[n];
    copy(a,b,n);
    copy(a,c,n);
    sort(c,c+n);
    int p = 0;
    int q = n-1;

    for(int i=n-1;i>=0;i--){
        if(i%2==0){
            b[i] = c[q];
            q--;
        }
        else{
            b[i]=c[p];
            p++;
        }
    }

    display(b,n);
}


int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a)/sizeof(a[0]);
    rearrangeArr(a,n);
}