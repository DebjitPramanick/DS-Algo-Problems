#include <bits/stdc++.h>
using namespace std;

// Searching in nearly sorted array

/*
In nearly sorted array an element which should be at i-th position, may be at (i-1) or (i+1)
*/

int binarySearch(int q, int a[], int n){
    int s = 0;
    int e = n;

    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==q) return mid;
        else if (a[mid-1]==q and (mid-1>s)) return mid-1;
        else if(a[mid+1] == q and (mid+1 < e)) return mid+1;
        else if(a[mid]>q) e = mid-2;
        else s = mid+2;
    }
    return -1;
}

int main(){
    int a[] = {5,10,30,20,40};
    int size = sizeof(a)/sizeof(a[0]);
    int s, res;
    cout<<"Enter elment to search: ";
    cin>>s;
    res = binarySearch(s, a, size);

    if(res == -1) cout<<"Element not found.";
    else cout<<"Element found at "<<res<<endl;
}