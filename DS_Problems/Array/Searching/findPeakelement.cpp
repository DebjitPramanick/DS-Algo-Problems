#include <bits/stdc++.h>
using namespace std;

// Given an array of integers. Find a peak
// element in it. An array element is a peak
// if it is NOT smaller than its neighbours.
// For corner elements, we need to consider
// only one neighbour.

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

void findPeakEl(int a[], int n)
{
    int b[n];
    copy(a, b, n);
    vector<int> ans;

    for (int i=0; i<n; i++)
    {
        if (i == 0 && b[i] > b[i+1]) ans.push_back(b[i]);
        else if(i == n-1 && b[i] > b[i-1]) ans.push_back(b[i]);
        else if(b[i]>b[i-1] && b[i]>b[i+1]) ans.push_back(b[i]);
    }

    for(auto it: ans){
        cout<<it<<" ";
    }
}

int main()
{
    int a[] = {10, 20};
    int n = sizeof(a) / sizeof(a[0]);
    findPeakEl(a, n);
}
