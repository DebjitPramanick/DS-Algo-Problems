#include <bits/stdc++.h>
using namespace std;

void topoSort(int n, vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(n+1, 0);

    // Filling indegree array with node's indegrees

    for(int i=1;i<=n;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    for(auto it: topo){
        cout<<it<<" ";
    }
}

void adjList(int n, int m){
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    } 

    cout<<"After appyling topological sort: ";
    topoSort(n, adj);
}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}