#include<bits/stdc++.h>
using namespace std;

// Find target sum of two elements in sorted rotated array
// Time complexity -> O(n)
// Finding pivot -> O(logn)

vector<int> pos;
void display(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void copy(int a[], int b[], int n){
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
}

int findMin(int a[], int n){
    int s = 0, e = n;
    while (s<=e)
    {
        int mid = (s+e)/2;
        int nxt = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(a[mid]<=a[nxt] and a[mid]<=a[prev]) return mid;
        else if(a[s]<=a[mid]) s=mid+1;
        else e=mid-1;
    }
    return -1;
}

bool findElements(int a[], int n, int t){
    int s = findMin(a,n);
    int e = (s+n-1)%n;
    while(s!=e){
        if(a[s]+a[e]==t) {
            pos.push_back(s);
            pos.push_back(e);
            return true;
        }
        else if(a[s]+a[e]<t) s = (s+1)%n;
        else e=(e+n-1)%n;
    }
    return false;
}

int main(){
    int a[] = {11, 15, 6, 8, 9, 10};
    int n =sizeof(a)/sizeof(a[0]);
    int target = 25;
    if(findElements(a,n,target)){
        cout<<"Elements are: "<<a[pos[0]]<<","<<a[pos[1]];
    }
    else cout<<"Not found.";
}
