#include <bits/stdc++.h>
using namespace std;

// Find last and first occurrence of element in sorted array

int findFirstOccurrence(int q, int a[], int n){
    int s = 0;
    int e = n;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==q){
            ans = mid;
            e = mid-1;
        }
        else if(a[mid]>q){
            e = mid-1;
        }
        else s = mid+1;
    }

    return ans;
}

int findLastOccurrence(int q, int a[], int n){
    int s = 0;
    int e = n;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==q){
            ans = mid;
            s = mid+1;
        }
        else if(a[mid]>q){
            e = mid-1;
        }
        else s = mid+1;
    }

    return ans;
}

int main(){
    int a[7] = {2,4,10,10,10,18,20};
    int size = sizeof(a)/sizeof(a[0]);
    int s, res1, res2;
    cout<<"Enter elment to search: ";
    cin>>s;
    res1 = findFirstOccurrence(s, a, size);
    res2 = findLastOccurrence(s, a, size);

    if(res1 == -1) cout<<"Element not found.";
    else cout<<"Element found at(first): "<<res1;

    cout<<endl;
    
    if(res1 != -1){
        if(res2 == -1) cout<<"Element not found.";
        else cout<<"Element found at(last): "<<res2;
    }

    cout<<endl;
}