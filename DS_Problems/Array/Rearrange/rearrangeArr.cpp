#include <bits/stdc++.h>
using namespace std;

// Rearrange an array such that arr[i] = i


void display(int a[], int n){
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void copy(int a[], int b[], int n){
    for (int i = 0; i < n; i++) b[i] = a[i];
}

void rearrange_Map(int a[], int n){ // O(n)
    int b[n];
    copy(a,b,n);
    map<int, int> mp;
    for(int i=0;i<n;i++){
        if(b[i] != -1) mp[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[i]) b[i] = i;
        else b[i] = -1;
    }

    display(b,n);
}

void rearrange_Loop(int a[], int n){
    int b[n];
    copy(a,b,n);
    for(int i=0;i<n;i++){
        if(b[i]!=-1 and b[i]!=i) {
            int x = b[i];
            while(b[x]!=-1 and b[x]!=x){
                int y = b[x];
                b[x] = x;
                x = y;
            }

            b[x] = x;
            if(b[i]!=i) b[i]=-1;
        }
    }

    display(b,n);
}

int main(){
    int a[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int n = sizeof(a)/sizeof(a[0]);
    rearrange_Map(a,n);
    rearrange_Loop(a,n);
}