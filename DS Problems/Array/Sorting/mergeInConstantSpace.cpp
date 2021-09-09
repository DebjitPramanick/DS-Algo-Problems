#include <bits/stdc++.h>
using namespace std;

// Given two sorted arrays, find their union and intersection.

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

int findPlace(int a[], int n, int key)
{
    int l = 0, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return l;
}

void merge1(int a[], int b[], int m, int n)
{
    int p[m], t[n];
    copy(a, p, m);
    copy(b, t, n);
    int i=0, j=0, k=m-1;

    while(i<=k and j<n){
        if(p[i]<t[j]) i++;
        else{
            swap(t[j], p[k]);
            j++, k--;
        }
    }

    sort(p, p+m);
    sort(t, t+n);

    display(p, m);
    display(t, n);
}

int main()
{
    int a[] = {1, 5, 9, 10, 15, 20};
    int b[] = {2, 3, 8, 13};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    merge1(a, b, m, n);
}
