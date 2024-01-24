#include <bits/stdc++.h>
using namespace std;

// Given an array of integers. All numbers occur twice except one number 
// which occurs once. Find the number in O(n) time & constant extra space.


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

void findElement(int a[], int n){
    int b[n];
    copy(a, b, n);
    int res = b[0];

    for(int i=1;i<n;i++){
        res = res ^ b[i];
    }

    cout<<res<<endl;

}

int main()
{
    int a[] = {7, 3, 5, 4, 5, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    findElement(a, n);
}
