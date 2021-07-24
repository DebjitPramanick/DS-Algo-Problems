#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int cur = a[i];
        int j = i-1;
        while(a[j] > cur && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cur;
    }
}

int main(){
    int a[] = {5, 2, 10, 9, 1, 4, 3, 7};
    int n = sizeof(a) / sizeof(a[0]);
    insertionSort(a, n);
    for(int i=0; i<n; i++) cout<<a[i]<<"->";
    cout<<endl;
}