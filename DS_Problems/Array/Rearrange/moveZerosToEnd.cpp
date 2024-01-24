#include <bits/stdc++.h>
using namespace std;

// Given an array of random numbers, Push all the zero’s 
// of a given array to the end of the array. For example, 
// if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, 
// it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. 
// The order of all other elements should be same. Expected 
// time complexity is O(n) and extra space is O(1).

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

    int count = 0;  
    for (int i = 0; i < n; i++){
        if (b[i] != 0){
            b[count] = b[i];
            count++;
        }
    }
    while (count < n)
        b[count++] = 0;

    display(b, n);
}

int main()
{
    int a[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(a) / sizeof(a[0]);
    rearrangeArr(a, n);
}