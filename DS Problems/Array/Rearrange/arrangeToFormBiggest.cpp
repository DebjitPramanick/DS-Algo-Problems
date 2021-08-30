#include <bits/stdc++.h>
using namespace std;

// Given an array of numbers, arrange them in a 
// way that yields the largest value. For example, 
// if the given numbers are {54, 546, 548, 60}, 
// the arrangement 6054854654 gives the largest 
// value. And if the given numbers are 
// {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 
// 998764543431 gives the largest value.



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
    copy(a, b, n);
    sort(b, b+n, compare);
    display(b,n);
    string res = "";
    for(int i=0;i<n;i++){
        res+=to_string(b[i]);
    }
    cout<<"Answer is: "<<res;
}

int main()
{
    int a[] = {1, 34, 3, 98, 9, 76, 45, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    arrangeArray(a, n);
}
