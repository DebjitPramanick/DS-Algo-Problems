#include <bits/stdc++.h>
using namespace std;

// Given an array of n distinct elements, find the 
// minimum number of swaps required to sort the array.

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


void mapSolution(int a[], int n){ // Time -> O(nlogn) Space -> O(n)
    int p[n], temp[n];
    copy(a, p, n);
    copy(p, temp, n);
    map<int, int> mp;
    int ans = 0;

    sort(temp, temp+n);
    
    for(int i=0;i<n;i++){
        mp[p[i]] = i;
    }

    for(int i=0;i<n;i++){
        if(p[i]!=temp[i]){
            ans++;
            int idx1 = mp[p[i]];
            int idx2 = mp[temp[i]];
            swap(p[idx1], p[idx2]);
        }
    }

    cout<<ans<<" ";
}

void minSWapRequired(int a[], int n){ // Graph Concept [Time -> O(nlogn) Space -> O(n)]
    int p[n];
    copy(a, p, n);
    pair<int,int> arrPos[n];

    for(int i=0;i<n;i++){
        arrPos[i].first = p[i];
        arrPos[i].second = i;
    }
    vector<int> vis(n, 0);
    int ans = 0;

    sort(arrPos, arrPos+n);

    for(int i=0;i<n;i++){

        if(vis[i] || arrPos[i].second == i) continue;

        int cycleSize = 0;
        int j = i;
        while(!vis[j]){
            vis[j] = 1;
            j = arrPos[i].second;
            cycleSize++;
        }

        if(cycleSize>0) ans+=cycleSize-1;
    }

    cout<<ans<<" ";
}

int main()
{
    int a[] = {4, 6, 5, 1, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    mapSolution(a, n);
}
