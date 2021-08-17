#include <bits/stdc++.h>
using namespace std;

// Find element in sorted rotated array

int binarySearch(int a[], int start, int end, int key){
    int s = start;
    int e = end;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==key) return mid;
        else if(a[mid]<key) s=mid+1;
        else e=mid-1;
    }
    return -1;
}

int findMinIdx(int a[], int n){
    int s = 0;
    int e = n;
    while(s<=e){
        int mid = (s+e)/2;
        int nxt = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(a[mid]<=a[nxt] and a[mid]<=a[prev]){
            return mid;
        }
        else if(a[s]<=a[mid]) s=mid+1;
        else e=mid-1;
    }
    return -1;
}

int findEl(int a[], int n, int key){
    int minIdx = findMinIdx(a, n);
    int lArr = binarySearch(a,0,minIdx-1,key);
    int rArr = binarySearch(a,minIdx,n,key);
    
    if(lArr != -1) return lArr;
    else if(rArr != -1) return rArr;
    return -1;
}

int main(){
    int a[8] = {11,12,15,18,2,5,6,8};
    int n = sizeof(a)/sizeof(a[0]);
    int res, s;
    cout<<"Enter element to search: ";
    cin>>s;
    res = findEl(a,n,s);
    if(res != -1) cout<<"Element found at: "<<res;
    else cout<<"Element not found.";
}