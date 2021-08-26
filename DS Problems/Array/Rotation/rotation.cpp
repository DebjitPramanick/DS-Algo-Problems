#include<bits/stdc++.h>
using namespace std;

// Utils functions
// Time complexity -> O(n)

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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void tempMethod(int a[], int n, int d){
    int temp[d], b[n], j=0;
    copy(a,b,n);
    for(int i=0;i<d;i++) temp[i] = b[i];
    for(int i=0;i<n-d;i++) b[i] = b[i+d];
    for(int i=n-d;i<n;i++){
         b[i] = temp[j];
         j++;
    }
    display(b,n);
}

void jugglingMethod(int a[], int n, int d){
    d = d%n;
    int GCD = gcd(d,n);
    int b[n];
    copy(a,b,n);
    for(int i=0;i<GCD;i++){
        int temp = b[i];
        int j=i;
        while(1){
            int k = j+d;
            if(k>=n) k = k-n;
            if(k==i) break;
            b[j] = b[k];
            j=k;
        }
        b[j] = temp;
    }
    display(b,n);
}


int main(){
    int a[] = {2,7,1,4,9,10,8,5,3}; 
    int n = sizeof(a)/sizeof(a[0]);
    int d = 3;
    tempMethod(a, n, d);
    jugglingMethod(a, n, d);
}