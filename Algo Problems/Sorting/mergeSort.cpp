#include <bits/stdc++.h>
using namespace std;

// Key -> Find middle element of an array and divide array in two parts, 
// then sort those parts and merge them


void merge(int a[], int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;

    int m[n1];
    int p[n2];
    for(int i=0;i<n1;i++) m[i] = a[l+i];
    for(int i=0;i<n2;i++) p[i] = a[mid+1+i];

    int i=0, j=0, k=l;

    while(i<n1 && j<n2){
        if(m[i] < p[j]){
            a[k]=m[i];
            k++, i++;
        }
        else{
            a[k]=p[j];
            k++, j++;
        }
    }

    while(i<n1){
        a[k] = m[i];
        i++, k++;
    }

    while(j<n2){
        a[k] = p[j];
        j++, k++;
    }

}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

int main(){
    int a[] = {5, 2, 10, 9, 1, 4, 3, 7};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << "->";
    cout << endl;
}