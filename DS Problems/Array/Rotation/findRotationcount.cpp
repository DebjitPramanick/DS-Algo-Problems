#include<bits/stdc++.h>
using namespace std;

// Find number of rotations

int findRotation(int a[], int n){
    int s = 0, e = n;
    int c = 0;
    while (s<=e)
    {
        int mid = (s+e)/2;
        int nxt = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(a[mid]<a[nxt] and a[mid]<a[prev]){
            c =  mid;
            break;
        }
        else if(a[s]<=a[mid]) s=mid+1;
        else e=mid-1;
    }
    return n-c; // For anti-clock wise rotation
    // return c; // For clock wise rotation
}


int main(){
    int a[] = {15, 18, 2, 3, 6, 12};
    int n =sizeof(a)/sizeof(a[0]);
    int res = findRotation(a,n);
    cout<<res;
}

