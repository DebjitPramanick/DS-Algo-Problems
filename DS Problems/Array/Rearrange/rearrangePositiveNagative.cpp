#include <bits/stdc++.h>
using namespace std;

// An array contains both positive and negative numbers in random order.
// Rearrange the array elements so that positive and negative numbers
// are placed alternatively. Number of positive and negative numbers need
// not be equal. If there are more positive numbers they appear at the end
// of the array. If there are more negative numbers, they too appear in
// the end of the array.
// For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9],
// then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]

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
{ // O(n)
    int b[n];
    copy(a, b, n);
    int i = -1;
    display(b, n);
    for (int j = 0; j < n; j++)
    {
        if (b[j] < 0)
        {
            i++;
            swap(b[i], b[j]);
        }
    }
    display(b, n);

    int pos = i + 1, neg = 0;
    while (pos < n and neg < pos and b[neg] < 0)
    {
        swap(b[neg], b[pos]);
        pos++;
        neg += 2;
    }

    display(b, n);
}

int main()
{
    int a[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    rearrangeArr(a, n);
}