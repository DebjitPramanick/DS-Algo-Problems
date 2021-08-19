#include <bits/stdc++.h>
using namespace std;

// Searching in nearly sorted array

/*
Find floor of an element in sorted array
*/

int findFloor(int q, int a[], int n){
    int s = 0;
    int e = n;
    int res;

    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==q){
            res = mid;
            break;
        }
        else if(a[mid]>q) e = mid-1;
        else{
            res = mid;
            s = mid+1;
        }
    }

    return res;
}

int main(){
    int a[] = {5,10,10,20,25,30,40};
    int size = sizeof(a)/sizeof(a[0]);
    int s, res;
    cout<<"Enter elment to search: ";
    cin>>s;
    res = findFloor(s, a, size);

    if(res == -1) cout<<"Floor not found.";
    else cout<<"Floor found at "<<res<<" = "<<a[res]<<endl;
}
