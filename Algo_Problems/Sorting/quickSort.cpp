#include<bits/stdc++.h>
using namespace std;

// Key -> Select a pivot element and keep smaller elements before the pivot element and greater elements
// after the pivot element. Then sort the smaller and greater elements again.

int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    cout<<i+1<<"\t";
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int pi = partition(a, l, r);
        quickSort(a, l, pi-1);
        quickSort(a, pi+1, r);
    }
}

int main(){
    int a[] = {4,2,9,6,1,3};
    quickSort(a, 0, 5);
    cout<<endl;
    for(int i=0;i<6;i++){
        cout<<a[i]<<"  ";
    }
}