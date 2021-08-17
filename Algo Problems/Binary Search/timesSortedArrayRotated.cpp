#include <bits/stdc++.h>
using namespace std;

// Find how many times a sorted array is rotated

/*

1. We have to find the minimum element in the rotated sorted array
2. For binary search the mid element must be less than both rigth and left element
3. Now we have to search for min element in the unsorted part of rotated sorted array

*/

void timesRotated(int a[], int n){
    int s = 0;
    int e = n;
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;
        int nxt = (mid+1)%n; // For not going out of bound
        int prev = (mid+n-1)%n; // For not going out of bound
        if(a[mid] <= a[nxt] and a[mid]<=a[prev]){
            ans = mid;
            break;
        }
        else if(a[s]<=a[mid]) s=mid+1; // Moves towards unsorted array
        else e=mid-1; // Moves towards unsorted array
    }

    cout<<"Number of times array rotated: "<<ans;
}



int main(){
    int a[8] = {11,12,15,18,2,5,6,8};
    int n = sizeof(a)/sizeof(a[0]);
    timesRotated(a, 8);
}