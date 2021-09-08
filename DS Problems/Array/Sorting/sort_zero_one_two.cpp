#include <bits/stdc++.h>
using namespace std;

// Given an array A[] consisting 0s, 1s and 2s. The
// task is to write a function that sorts the given array.
// The functions should put all 0s first, then all 1s and
// all 2s in last.

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

void sortZeroOneTwos(int a[], int n){ // Time -> O(n)
    int b[n];
    copy(a, b, n);

    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        switch (b[i])
        {
        case 0:
            c0++;
            break;
        case 1:
            c1++;
            break;
        case 2:
            c2++;
            break;
        default:
            break;
        }
    }

    int i = 0;

    while(c0>0) {
        b[i++] = 0;
        c0--;
    }

    while(c1>0) {
        b[i++] = 1;
        c1--;
    }

    while(c2>0) {
        b[i++] = 2;
        c2--;
    }

    display(b, n);
}

void sort012(int a[], int n)
{ // Time -> O(n)
    int b[n];
    copy(a, b, n);

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        switch (b[mid])
        {
        case 0:
            swap(b[low++], b[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(b[mid], b[high--]);
            break;
        default:
            break;
        }
    }

    display(b, n);
}

int main()
{
    int a[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    sortZeroOneTwos(a, n);
    sort012(a, n);
}