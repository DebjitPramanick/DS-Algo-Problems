#include <bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis){
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto it: adj[node]){
        if(vis[it] == 0){
            if(checkCycleDFS(it, adj, vis, dfsVis)) return true;
        }
        else if(dfsVis[it]) return true;
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n, 0), dfsVis(n, 0);

    for(int i=1;i<=n; i++){
        if(!vis[i]){
            if(checkCycleDFS(i, adj, vis, dfsVis)) return true;
        }
    }

    return false;
}

void adjList(int n, int m){
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    } 

    bool cycle =  isCycle(n, adj);
    if(cycle){
        cout<<"Graph is cyclic.";
    }
    else{
        cout<<"Graph is not cyclic.";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}