#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> adj[], stack<int> &s, vector<int> &vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            findTopoSort(it, adj, s, vis);
        }
    }
    s.push(node);
}

void topoSort(int n, vector<int> adj[]){
    vector<int> vis(n+1, 0);
    stack<int> s;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            findTopoSort(i, adj, s, vis);
        }
    }

    while(!s.empty()){
        int node = s.top();
        cout<<node<<"  ";
        s.pop();
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