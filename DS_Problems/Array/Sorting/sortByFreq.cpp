#include <bits/stdc++.h>
using namespace std;

// Print the elements of an array in the decreasing frequency 
// if 2 numbers have same frequency then print the one which came first. 

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

void insertionsort(int a[], int n){
    for(int i=0;i<n;i++){
        int cur = a[i];
        int j = i-1;
        while(a[j]>cur && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cur;
    }
}

bool fcompare(pair<int, pair<int, int> > p,
              pair<int, pair<int, int> > p1)
{
    if (p.second.second != p1.second.second)
        return (p.second.second > p1.second.second);
    else
        return (p.second.first < p1.second.first);
}

void sortByFreq(int a[], int n){
    int b[n];
    copy(a,b,n);
    map<int, pair<int, int>> mp;

    for(int i=0; i<n; i++){
        if(mp.find(b[i]) != mp.end()) mp[b[i]].second++;
        else mp[b[i]] = make_pair(i, 1);
    }

    vector<pair<int, pair<int,int>>> vp;

    for(auto it: mp){
        vp.push_back(make_pair(it.first, it.second));
    }

    sort(vp.begin(), vp.end(), fcompare);

    for(int i=0;i<vp.size();i++){
        int c = vp[i].second.second;
        while(c--){
            cout<<vp[i].first<<"  ";
        }
    }
}

int main()
{
    int a[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int n = sizeof(a) / sizeof(a[0]);
    sortByFreq(a, n);
}