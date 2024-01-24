#include <bits/stdc++.h>
using namespace std;

bool checkUsingTopoSort(int n, vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(n+1, 0);

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

    int cnt = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(cnt == n) return false;
    return true;
}

bool checkCycleUtil(int i, vector<int> &vis, vector<int> &recStack, vector<int> adj[]){
    vis[i] = 1;
    recStack[i] = 1;

    for(auto it: adj[i]){
        if(!vis[it] && checkCycleUtil(it, vis, recStack, adj)) return true;
        else if(recStack[it]) return true;
    }

    recStack[i] = false;
    return false;
}

bool checkCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1, 0);
    vector<int> recStack(n+1, 0);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkCycleUtil(i, vis, recStack, adj)) return true;
        }
    }

    return false;
}

bool isCycle(int n, vector<int> adj[]){
    // if(!checkUsingTopoSort(n, adj)) return false;
    if(!checkCycle(n, adj)) return false;
    return true;
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