#include<bits/stdc++.h>
using namespace std;

// Find max hamming distance of array elements [See hamming distance on Google]
// Time complexity -> O(n)

int findHammingDistance(int a[], int n){

    int b[2*n+1];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    for (int i = 0; i < n; i++)
        b[n+i] = a[i];
    
    int maxHam = 0;

    for(int i=1; i<n;i++){
        int curHam = 0;
        for(int j=i, k=0; j<(n+i);j++,k++){
            if(b[j]!=a[k]) curHam++;
        }
        if(curHam == n) return n;
        maxHam = max(maxHam, curHam);
    }

    return maxHam;
}


int main(){
    int a[] = {2,4,8,0}; 
    int n = sizeof(a)/sizeof(a[0]);
    int ans = findHammingDistance(a,n);
    cout<<ans;
}