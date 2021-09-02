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

void findMajority(int a[], int n){
    int p[n];
    copy(a, p, n);
    map<int,int> mp;
    int ans = -1;

    for(int i=0;i<n;i++) mp[p[i]]++;
    for(auto it: mp){
        if(it.second >= n/2){
            ans = it.first;
            break;
        }
    }
    cout<<"Majority element is: "<<ans<<endl;
}

// Using Moore’s Voting Algorithm O(n) and O(1)

int findCandidate(int a[], int n){
    int p[n];
    copy(a, p, n);
    int mj_idx = 0, count = 1;
    for(int i=1;i<n;i++){
        if(p[mj_idx]==p[i]) count++;
        else count--;
        if(count == 0){
            mj_idx = i;
            count = 1;
        }
    }
    return p[mj_idx];
}

bool isMajority(int a[], int n, int k){
    int p[n];
    copy(a, p, n);
    int c = 0;
    for(int i=0;i<n;i++) {
        if(p[i] == k) c++;
    }
    if(c>n/2) return true;
    return false;
}

void findMajorityV2(int a[], int n){
    int cand = findCandidate(a, n);
 
    /* Print the candidate if it is Majority*/
    if (isMajority(a, n, cand)) cout << " " << cand << " ";
    else cout << "No Majority Element";
}

int main()
{
    int a[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(a) / sizeof(a[0]);
    findMajorityV2(a, n);
}
