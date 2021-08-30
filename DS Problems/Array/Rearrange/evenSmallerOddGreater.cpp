#include <bits/stdc++.h>
using namespace std;

// Rearrange array such that even index elements 
// are smaller and odd index elements are greater


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


void rearrangeArray(int a[], int n){
    int b[n];
    copy(a, b, n);

    for(int i=0;i<n-1;i++){
        if (i % 2 == 0 && b[i] > b[i + 1])
            swap(b[i], b[i + 1]);
 
        if (i % 2 != 0 && b[i] < b[i + 1])
            swap(b[i], b[i + 1]);
    }

    display(b, n);
}


int main()
{
    int a[] = {2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    rearrangeArray(a, n);
}
