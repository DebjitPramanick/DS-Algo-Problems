#include <bits/stdc++.h>
using namespace std;

/*
Given two integer arrays arr1[] and arr2[] sorted in ascending 
order and an integer k. Find k pairs with smallest sums such that 
one element of a pair belongs to arr1[] and other element belongs 
to arr2[]
*/

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void findKPairs(int a[], int n1, int b[], int n2, int k){
    priority_queue<pair<int, pair<int, int> >,
                   vector<pair<int, pair<int, int> > >,
                   greater<pair<int, pair<int, int> > > >
        pq; // Mean-heap using priority queue
    set<pair<int, int>> st;

    pq.push(make_pair(a[0]+b[0], make_pair(0, 0)));
    st.insert(make_pair(0,0));

    int flag = 1;

    for(int i=0;i<k and flag; i++){
        pair<int, pair<int, int>> tp = pq.top();
        pq.pop();
        cout<<tp.first<<"->"<<a[tp.second.first]<<"+"<<b[tp.second.second]<<endl;

        int m = tp.second.first;
        int n = tp.second.second;

        flag = 0;

        if(m+1<n1){
            pair<int, int> temp = make_pair(m+1, n);
            int sum = a[m+1] + b[n];
            if(st.find(temp) == st.end()){
                pq.push(make_pair(sum, temp));
                st.insert(temp);
            }
            flag = 1;
        }

        flag = 0;

        if(n+1<n2){
            pair<int, int> temp = make_pair(m, n+1);
            int sum = a[m] + b[n+1];
            if(st.find(temp) == st.end()){
                pq.push(make_pair(sum, temp));
                st.insert(temp);
            }
            flag = 1;
        }
        
        
    }



    
}



int main()
{
    int a[] = {1, 7, 11};
    int b[] = {2, 4, 6};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    findKPairs(a, n1, b, n2, 3);
}
