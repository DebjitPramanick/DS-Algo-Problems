#include<bits/stdc++.h>
using namespace std;

bool findPathWithLengthK(int src, int k, vector<pair<int,int>> adj[], vector<int> &vis){
    vis[src] = 1;
    if(k<=0) return true;

    for(auto it: adj[src]){
        int u = it.first;
        int wt = it.second;
        if(vis[u]) continue;
        if(wt>=k) return true;
        if(findPathWithLengthK(u, k-wt, adj, vis)) return true;

    }

    vis[src] = 0;
    return false;
}

void adjList(int n, int m){
    vector<pair<int,int>> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<int> vis(n+1, 0);
    int k = 23;

    cout<<findPathWithLengthK(1, k, adj, vis)<<endl;


}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}