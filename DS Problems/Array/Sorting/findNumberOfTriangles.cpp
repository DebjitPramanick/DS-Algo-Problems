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

void findNumberOfTriangles(int a[], int n)
{
    int p[n];
    copy(a, p, n);
    sort(p, p + n);
    int count = 0;
    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 1; i--)
    {
        while (l < r)
        {
            if (p[l] + p[r] > p[i])
            {
                count += r - l;
                r--;
            }
            else
            {
                l++;
            }
        }
    }

    cout << count << " ";
}

int main()
{
    int a[] = {4, 3, 5, 7, 6};
    int n = sizeof(a) / sizeof(a[0]);
    findNumberOfTriangles(a, n);
}
