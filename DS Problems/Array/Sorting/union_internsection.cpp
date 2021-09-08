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

void find_Union_Intersection(int a[], int b[], int m, int n){
    int p[m], t[n];
    copy(a, p, m);
    copy(b, t, n);

    int i = 0, j = 0;
    vector<int> ans;

    while(i<m and j<n){
        if(p[i]<t[j]) cout<<p[i++]<<" ";
        else if(p[i]>t[j]) cout<<t[j++]<<" ";
        else{
            cout<<t[j]<<" ";
            ans.push_back(p[i++]);
            j++;
        }
    }

    while (i<m){
        cout<<p[i++]<<" ";
    }
    while (j<n){
        cout<<t[j++]<<" ";
    }

    cout<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }
    
}

int main()
{
    int a[] = {1, 3, 4, 5, 7};
    int b[] = {2, 3, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    find_Union_Intersection(a, b, m, n);
}
