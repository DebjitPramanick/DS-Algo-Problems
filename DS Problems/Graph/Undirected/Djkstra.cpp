#include<bits/stdc++.h>
using namespace std;


void findDjkstraPath(int n, vector<pair<int,int>> adj[]){
    int source;
    cout<<"Enter source: ";
    cin>>source;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // Min heap
    vector<int> dist(n+1, INT_MAX);

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int nextNode = it.first;
            int nextDist = it.second;
            if(dist[nextNode] > distance+nextDist){
                dist[nextNode] = distance+nextDist;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }

    cout<<"The shortest path of each node from source are: ";
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}


void adjList(int n, int m){
    vector<pair<int,int>> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    findDjkstraPath(n, adj);


}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}