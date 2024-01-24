#include<bits/stdc++.h>
using namespace std;


void findShortestPath(int n, vector<int> adj[], int src){
    // Take a distance array
    int dist[n+1];

    for(int i=1;i<=n;i++){
        dist[i] = INT_MAX;
    }

    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto i: adj[node]){
            if(dist[node] + 1 < dist[i]){
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

    cout<<"The shortest path of each node are: ";
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }


}


void adjList(int n, int m){
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findShortestPath(n, adj, 1);
}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}