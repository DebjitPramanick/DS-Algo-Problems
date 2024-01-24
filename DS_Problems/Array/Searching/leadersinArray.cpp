#include <bits/stdc++.h>
using namespace std;

// Write a program to print all the LEADERS in 
// the array. An element is leader if it is greater 
// than all the elements to its right side. 
// And the rightmost element is always a leader. For 
// example int the array {16, 17, 4, 3, 5, 2}, 
// leaders are 17, 5 and 2. Let the input array be 
// arr[] and size of the array be size.


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

void findLeaders(int a[], int n){
    int p[n];
    copy(a, p, n);
    vector<int> ans;
    int max = INT_MIN;
    for(int i=n-1;i>0;i--){
        if(p[i]>max) {
            ans.push_back(p[i]);
            max = p[i];
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto it: ans) cout<<it<<" ";
}

int main()
{
    int a[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    findLeaders(a, n);
}
