#include <bits/stdc++.h>
using namespace std;

// Given an array and a value, find if there is 
// a triplet in array whose sum is equal to the given 
// value. If there is such a triplet present in array, 
// then print the triplet and return true. Else return false.

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

void findTripletSum(int a[], int n, int sum)
{
    int b[n];
    copy(a, b, n);
    vector<int> ans;
    sort(b, b+n);

    for(int i=0;i<n;i++){
        int target = sum - b[i];
        int l = i+1, r = n-1;
        for(int j=i;j<n;j++){
            if(b[l]+b[r]>target) r--;
            else if(b[l]+b[r]<target) l++;
            else{ 
                cout<<"["<<b[l]<<", "<<b[r]<<", "<<b[i]<<"]"<<endl;
            }
        }
    }
}

int main()
{
    int a[] = {11, 3, 4, 1, 6, 9};
    int n = sizeof(a) / sizeof(a[0]);
    findTripletSum(a, n, 16);
}
