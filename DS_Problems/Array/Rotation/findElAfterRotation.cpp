#include <bits/stdc++.h>
using namespace std;

// Find element at given index after certain right rotations
// Time complexity -> O(n)

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void copy(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

int findEL(int a[], int n, int rt[][2], int index)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int l = rt[i][0];
        int r = rt[i][1];
        if (l <= index && r >= index)
        {
            if (l == index)
                index = r;
            else
                index--;
        }
    }
    return a[index];
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int d = 2;
    int rotations[d][2] = {{0, 2}, {0, 3}};
    int i = 0;
    int ans = findEL(a, d, rotations, i);
    cout << ans << endl;
}