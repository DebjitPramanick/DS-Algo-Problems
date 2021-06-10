#include <bits/stdc++.h>
using namespace std;


bool bipartiteDFS(int node, vector<int> adj[], int color[]){
    if(color[node] == -1) color[node] = 1;
    for(auto it: adj[node]){
        if(color[it] == -1){
            color[it] = 1 - color[node];
            if(!bipartiteDFS(it, adj, color)) return false;
        }
        else if(color[it] == color[node]) return false;
    }
    return true;
}


bool bipartiteBFS(int node, vector<int> adj[], int color[]){
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while(!q.empty()){
        int fn = q.front();
        q.pop();
        for(auto it: adj[fn]){
            if(color[it] == -1){
                color[it] = 1 - color[fn];
                q.push(it);
            }
            else if(color[it] == color[fn]){
                return false;
            }
        }
    }

    return true;
}


bool isBipartite(int n, vector<int> adj[]){
    int color[n];
    memset(color, -1, sizeof color);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bipartiteDFS(i, adj, color)) return false;
        }
    }
    return true;
}


void adjList(int n, int m){
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    bool bp =  isBipartite(n, adj);
    if(bp) cout<<"Graph is bipartite.";
    else cout<<"Graph is not bipartite.";
}


int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}
