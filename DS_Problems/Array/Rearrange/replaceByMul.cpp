#include <bits/stdc++.h>
using namespace std;

// Given an array of integers, update every element 
// with multiplication of previous and next elements 
// with following exceptions. 
// a) First element is replaced by multiplication of first and second. 
// b) Last element is replaced by multiplication of last and second last.


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

bool compare(int x, int y){
    int xy = stoi(to_string(x)+to_string(y));
    int yx = stoi(to_string(y)+to_string(x));
    if(xy>yx) return true;
    return false;
}

void arrangeArray(int a[], int n){
    int b[n];
    if (n <= 1) return;
    copy(a, b, n);
    int prev = b[0];
    b[0] = b[0]*b[1];

    for(int i=1;i<n-1;i++){
        int cur = b[i];
        b[i] = prev*b[i+1];
        prev = cur;
    }

    b[n-1]=prev*b[n-1];

    display(b, n);
}

int main()
{
    int a[] = {2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    arrangeArray(a, n);
}
