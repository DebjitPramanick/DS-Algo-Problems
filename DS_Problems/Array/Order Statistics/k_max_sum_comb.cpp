#include <bits/stdc++.h>
using namespace std;

/*
Given two equally sized arrays (A, B) and N (size of both arrays). 
A sum combination is made by adding one element from array A and 
another element of array B. Display the maximum K valid sum 
combinations from all the possible sum combinations. 
*/

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void insSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int c = arr[i];
        int j = i - 1;
        while (c < arr[j] and j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = c;
    }
}

void findKvalidSums_PQ(int a[], int n1, int b[], int n2, int k){
    insSort(b, n2);
    insSort(a, n1);
    
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;

    pq.push(make_pair((a[n1-1] + b[n2-1]), make_pair(n1-1, n2-1)));
    st.insert(make_pair(n1-1, n2-1));

    for(int c =0;c <k;c++){
        pair<int, pair<int, int>> tp = pq.top();
        pq.pop();
        cout<<tp.first<<endl;

        int i = tp.second.first;
        int j = tp.second.second;

        int s = a[i-1] + b[j];
        pair<int, int> temp = make_pair(i-1, j);

        if(st.find(temp) == st.end()){
            pq.push(make_pair(s, temp));
            st.insert(temp);
        }

        s = a[i] + b[j-1];
        temp = make_pair(i, j-1);

        if(st.find(temp) == st.end()){
            pq.push(make_pair(s, temp));
            st.insert(temp);
        }
    }
}

void findKvalidSums(int a[], int n1, int b[], int n2, int k){
    insSort(b, n2);
    insSort(a, n1);
    display(b, n2);

    vector<int> ans;
    int max = INT_MIN;

    for (int i = n1-1; i > 0; i--){
        if(i<n1-1 and a[i] != a[i+1] and k>0){
            ans.push_back(a[i] + b[n2 - 1]);
            k--;
        }
        else{
            ans.push_back(a[i] + b[n2 - 1]);
            k--;
        }
    }

    for(auto it: ans){
        cout<<it<<endl;
    }
}

int main()
{
    int a[] = {4, 2, 5, 1};
    int b[] = {8, 0, 3, 5};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    findKvalidSums(a, n1, b, n2, 3);
    findKvalidSums_PQ(a, n1, b, n2, 3);
}
