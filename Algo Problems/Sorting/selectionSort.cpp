#include <bits/stdc++.h>
using namespace std;

// Key -> Find minimium element in unsorted array and swap it with the begining element

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j < n; j++){
            if(a[j]<a[i]) swap(a[j], a[i]);
        }
    }
}

int main(){
    int a[] = {5, 2, 10, 9, 1, 4, 3, 7};
    int n = sizeof(a) / sizeof(a[0]);
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << "->";
    cout << endl;
}