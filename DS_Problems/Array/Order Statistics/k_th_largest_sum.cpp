#include <bits/stdc++.h>
using namespace std;

// Given an array of integers. Write a program to find 
// the K-th largest sum of contiguous subarray within the 
// array of numbers which has negative and positive numbers.

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

void findKthLargestSum(int a[], int n, int k){
    int b[n];
    copy(a,b,n);
    int sum[n+1];
    sum[0] = 0;
    sum[1] = b[0];

    for(int i=2;i<=n;i++){
        sum[i] = sum[i-1] + b[i-1];
    }

    priority_queue<int, vector<int>, greater<int>> pq; //Min heap

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x = sum[j]-sum[i-1];
            if(pq.size() < k) pq.push(x);
            else{
                if(pq.top()<x){
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }

    cout<<pq.top()<<endl;
}

int main()
{
    int a[] = {10, -10, 20, -40};
    int n = sizeof(a) / sizeof(a[0]);
    findKthLargestSum(a, n, 3);
}
