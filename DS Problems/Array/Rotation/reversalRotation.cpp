#include<bits/stdc++.h>
using namespace std;

// Rotate array using reversal algo

void display(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void copy(int a[], int b[], int n){
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
}


void reverse(int a[], int s, int e){
    while(s<e){
        swap(a[s], a[e]);
        s++, e--;
    }
}

void applyReversal(int a[], int n, int d){
    int b[n];
    copy(a,b,n);
    if(d==0) return;
    d = d%n;

    reverse(b,0,d-1);
    reverse(b,d,n-1);
    reverse(b,0,n-1);
    display(b,n);
}


int main(){
    int a[] = {2,7,1,4,9,10,8,5,3}; 
    int n = sizeof(a)/sizeof(a[0]);
    int d = 3;
    applyReversal(a,n,d);
}