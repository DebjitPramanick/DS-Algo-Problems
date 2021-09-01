#include <bits/stdc++.h>
using namespace std;

// Given an array and a number k where k is smaller 
// than the size of the array, we need to find the 
// k’th smallest element in the given array. It is 
// given that all array elements are distinct.



void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void copy(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

void findKthElement(int a[], int n, int k){ // Using map
    int b[n];
    copy(a, b, n);
    map<int,int> mp;
    int p = 0, ans;

    for(int i=0;i<n;i++) mp[b[i]]++;

    for(auto it: mp){
        p+=it.second;
        if(p>=k) {
            ans=it.first;
            break;
        }
    }

    cout<<ans<<endl;
}

int partition(int a[], int l, int r){
    int x = a[r], i = l;
    for(int j=l;j<r;j++){
        if(a[j]<=x){
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[i],a[r]);
    return i;
}

int findKthElementV2(int b[], int l, int r, int k){ // Using quicksort

    if(k>0 and k<=(r-l+1)){
        int pos = partition(b, l, r);
        if(pos-l == k-1) return b[pos];
        if(pos-l > k-1) return findKthElementV2(b, l, pos-1, k);
        else return findKthElementV2(b, pos+1, r, k-pos+l-1);
    }

    return INT_MAX;
}

int main()
{
    int a[] = {7,0,25,6,16,17,0};
    int n = sizeof(a) / sizeof(a[0]);
    findKthElement(a, n, 3);
    int b[n];
    copy(a, b, n);
    int ans = findKthElementV2(b, 0, n-1, 3);
    cout<<endl<<ans<<endl;
}
