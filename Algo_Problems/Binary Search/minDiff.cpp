#include <bits/stdc++.h>
using namespace std;

// Find min difference of elements from a key in sorted array

int findMinDiff(int a[], int n, int key){
    int s=0 ;
    int e=n-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(key == a[mid]) return a[mid]-key;
        else if(a[mid]>key) e=mid-1;
        else s=mid+1;
    }

    return min(abs(a[s]-key),abs(a[e]-key));
}


int main(){
    int a[] = {1,3,8,10,15};
    int size = sizeof(a)/sizeof(a[0]);
    int res;

    res = findMinDiff(a, size, 12);
    if(res == -1) cout<<"Not solved.";
    else cout<<"Min difference is: "<<res;
}
