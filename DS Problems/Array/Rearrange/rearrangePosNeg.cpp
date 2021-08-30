#include <bits/stdc++.h>
using namespace std;

// You have been given an array and you have to make 
// a program to convert that array such that positive 
// elements occur at even numbered places in the array 
// and negative elements occur at odd numbered places 
// in the array. We have to do it in place. There can 
// be unequal number of positive and negative values 
// and the extra values have to left as it is.



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


void rearrangeArray(int a[], int n){
    int b[n];
    copy(a, b, n);

    int pos = 0, neg = 1;
    while(true){
        while(pos<n && b[pos]>=0) pos+=2;
        while(neg<n && b[neg]<=0) neg+=2;
        if(pos<n && neg<n) swap(b[pos],b[neg]);
        else break;
    }

    display(b, n);
}


int main()
{
    int a[] = {1, -3, 5, 6, -3, 6, 7, -4, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    rearrangeArray(a, n);
}
