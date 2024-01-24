#include <bits/stdc++.h>
using namespace std;

/*
Given an array of n numbers and a positive integer k. The 
problem is to find k numbers with most occurrences, i.e., 
the top k numbers having the maximum frequency. If two numbers 
have the same frequency then the larger number should be given 
preference. The numbers should be displayed in decreasing order 
of their frequencies. It is assumed that the array consists of 
k numbers with most occurrences.
*/

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second > b.second) return true;
    else if(a.second == b.second and a.first > b.first) return true;
    else if(a.second == b.second and a.first < b.first) return false;
    return false;
}

struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;

        return p1.second < p2.second;
    }
};

void findKNums_PQ(int a[], int n, int k){ // Method: (Hashmap, Priority Queue), Time: O(nlogn), Space: O(n)
    map<int, int> mp;
    

    for(int i=0;i<n;i++) mp[a[i]]++;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq(mp.begin(), mp.end());

    int i = 0;
    while(i<k){
        pair<int, int> tp = pq.top();
        pq.pop();
        i++;
        cout<<tp.first<<" "<<tp.second<<endl;
    }
}




void findKNums(int a[], int n, int k){ // Method: Hashmap, Time: O(nlogn), Space: O(n)
    map<int, int> mp;
    vector<pair<int, int>> ans;

    for(int i=0;i<n;i++) mp[a[i]]++;
    for(auto it: mp){
        ans.push_back(make_pair(it.first, it.second));
    }

    sort(ans.begin(), ans.end(), cmp);

    for(int i=0;i<k;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}

int main()
{
    int a[] = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    // findKNums(a, n, 4);
    findKNums_PQ(a, n, 4);
}
