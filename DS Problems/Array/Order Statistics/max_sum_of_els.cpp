#include <bits/stdc++.h>
using namespace std;

// Given an array of positive numbers, find the maximum 
// sum of a subsequence with the constraint that no 2 numbers 
// in the sequence should be adjacent in the array. So 3 2 7 10 
// should return 13 (sum of 3 and 10) or 3 2 5 10 7 should 
// return 15 (sum of 3, 5 and 7).Answer the question in most 
// efficient way. 



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

void findMaxSum(int a[], int n){
    int b[n];
    copy(a,b,n);

    int excl_new, excl = 0, incl = b[0];

    for(int i=1;i<n;i++){
        cout<<excl<<", "<<incl<<", "<<excl_new<<"--First"<<endl;
        excl_new = incl > excl ? incl : excl;
        incl = excl + b[i];
        excl = excl_new;
        cout<<excl<<", "<<incl<<", "<<excl_new<<"--Second"<<endl;
    }

    int ans = incl > excl ? incl : excl;
    cout<<ans<<endl;


}

int main()
{
    int a[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(a) / sizeof(a[0]);
    findMaxSum(a, n);
}
