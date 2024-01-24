#include <bits/stdc++.h>
using namespace std;


bool checkCycleDFS(int node, int prev, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(vis[it] == 0){
            if(checkCycleDFS(it, node, adj, vis)) return true;
        }
        else if(it != prev) return true;
    }

    return false;
}

bool checkCycleBFS(int node, int n, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    vis[node] = 1;
    q.push({node, -1});

    while (!q.empty())
    {
        int curNode = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[curNode])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, curNode});
            }
            else if (it != par)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1, 0);

    for(int i=1;i<=n; i++){
        if(!vis[i]){
            if(checkCycleDFS(i, -1, adj, vis)) return true;
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
        adj[v].push_back(u);
    } 

    bool cycle =  isCycle(n, adj);
    cout << cycle;
}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}