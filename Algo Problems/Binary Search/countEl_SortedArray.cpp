#include<bits/stdc++.h>
using namespace std;


// Find the count of a selected element in array


int firstIndex(int a[], int n, int k){
    int s = 0;
    int e = n;
    int idx = -1;
    
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] == k){
            idx = mid;
            e = mid-1;
        }
        else if(a[mid]<k){
            s=mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return idx;
}

int lastIndex(int a[], int n, int k){
    int s = 0;
    int e = n;
    int idx = -1;
    
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] == k){
            idx = mid;
            s = mid+1;
        }
        else if(a[mid]<k){
            s=mid+1;
        }
        else{
            e = mid-1;
        }
    }

    return idx;
}

int countFunc(int a[], int n, int key){
    int fI = firstIndex(a,n,key);
    int lI = lastIndex(a,n,key);

    if(fI == -1 || lI==-1){
        return -1;
    }
    return (lI-fI)+1;
}


int main(){
    int a[7] = {2,4,10,10,10,18,20};
    int size = sizeof(a)/sizeof(a[0]);
    int s, res;
    cout<<"Enter elment to search: ";
    cin>>s;

    res = countFunc(a, size, s);
    if(res!=-1) cout<<"Element occurred "<<res<<" times.";
    else cout<<"Element not found.";
}