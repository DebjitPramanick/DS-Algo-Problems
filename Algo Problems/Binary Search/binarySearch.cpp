#include <bits/stdc++.h>
using namespace std;

void sortArr(int a[], int n){
    for(int i=0;i<n;i++){
        int cur = a[i];
        int j = i-1;

        while(a[j]>cur && j>0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cur;
    }
}

int binarySearch(int q, int a[], int n){
    sortArr(a,n);
    int s = 0;
    int e = n;

    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==q) return mid;
        else if(a[mid]>q){
            e = mid-1;
        }
        else s = mid+1;
    }
    return -1;
}

int main(){
    int a[] = {2,4,3,5,7,8};
    int size = sizeof(a)/sizeof(a[0]);
    int s, res;
    cout<<"Enter elment to search: ";
    cin>>s;
    res = binarySearch(s, a, size);

    if(res == -1) cout<<"Element not found.";
    else cout<<"Element found.";
}