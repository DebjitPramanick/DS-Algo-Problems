#include <bits/stdc++.h>
using namespace std;

// Given an array of integers, task is to print the array 
// in the order – smallest number, Largest number, 2nd 
// smallest number, 2nd largest number, 3rd smallest number, 
// 3rd largest number and so on…..

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

void rearrangeArr(int a[], int n){ // Complexity O(logn)
    int b[n], c[n];
    copy(a, b, n);
    sort(b,b+n);
    int p = 0, q = n-1, i = 0;

    while(p<=q){
        if(i%2 == 0){
            c[i] = b[p];
            p++;
        }
        else{
            c[i] = b[q];
            q--;
        }
        i++;
    }
    display(c, n);
}

int main()
{
    int a[] = {5, 8, 1, 4, 2, 9, 3, 7, 6};
    int n = sizeof(a) / sizeof(a[0]);
    rearrangeArr(a, n);
}
