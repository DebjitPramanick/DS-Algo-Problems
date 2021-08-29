#include <bits/stdc++.h>
using namespace std;

// Given an array of positive and negative numbers,
// arrange them such that all negative integers appear
// before all the positive integers in the array
// without using any additional data structure like hash
// table, arrays, etc. The order of appearance should
// be maintained.

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

void rearrangeArr(int a[], int n)
{
    int b[n];
    copy(a, b, n);

    for (int i = 0; i < n; i++){
        int cur = b[i];
        if (cur < 0){
            int j = i - 1;
            cout << cur << " " << b[j] << " " << j << endl;
            while (b[j] > 0 && j >= 0)
            {
                b[j + 1] = b[j];
                j--;
            }
            b[j + 1] = cur;
        }
    }

    display(b, n);
}

int main()
{
    int a[] = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(a) / sizeof(a[0]);
    rearrangeArr(a, n);
}
