#include <bits/stdc++.h>
using namespace std;

/*
We are given n files with their computation times in array. Find minimum cost to
execute all files.
Operation: Choose/take any two files, add their computation times and append
it to the list of computation times.
{Cost = Sum of computation time}

Do this untill we are left with only one file in the array.
We have to do this operation such that we get minimum cost finally.
*/

bool cmp(vector<int> a, vector<int> b){
    double m = (double) a[1]/a[0];
    double n = (double) b[1]/b[0];
    // We will find price of uint weight

    return m>n;
}

int main(){
    vector<int> times = {5, 2, 4, 7};

    /*
    (2+4) + (2+4+5) + (2+4+5+7) = 35
    */

    int n = times.size();

    priority_queue<int, vector<int>, greater<int>> pq; // Min-Heap

    for(int i=0;i<n;i++) pq.push(times[i]);

    int ans =0;

    while(pq.size()>1){
        int e1 = pq.top(); // Taking first task
        pq.pop();
        int e2 = pq.top(); // Taking second task
        pq.pop();
        ans+=e1+e2;
        pq.push(e1+e2); // Pushing sumn of chosen tasks to heap
    }

    cout<<"Min cost: "<<ans<<endl;

}