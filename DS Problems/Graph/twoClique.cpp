/*
Steps:

1. Reverse the graph
2. Check if graph is bipartite
3. If true graph can be divided
*/


/*
Time complexity -> O(N^2)
Space Complexity -> O(N+E)+O(N)+O(N)
*/


#include<bits/stdc++.h>
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


void checkForTwoParts(int n, vector<int> adj[]){
    vector<int> reverse[n+1];
    vector<int> dummy(n+1, 0);

    for(int i=1;i<=n;i++){
        dummy[i] = 1;
        for(auto it: adj[i]) dummy[it] = 1;
        for(int j=1;j<=n;j++){ 
            // Check which nodes are not adjacent to current node i,
            // and push those nodes as adjacent nodes of node i
            if(dummy[j]==0){
                reverse[i].push_back(j);
                reverse[j].push_back(i);
            }
        }
        dummy.clear();
    }

    bool flag = isBipartite(n, reverse);
    if(flag){
        cout<<"Graph can be divided into two cliques."<<endl;
    }
    else{
        cout<<"Graph cannot be divided into two cliques."<<endl;
    }
}


void adjList(int n, int m){
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v;
        cout<<"Enter two nodes: "<<endl;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    checkForTwoParts(n, adj);
}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}