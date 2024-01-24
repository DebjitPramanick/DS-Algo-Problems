/*
Steps:

1. Sort all the nodes in order of finishing time -> Toposort
2. Transpose the graph
3. DFS traversal according to the finishing time
*/


/*
Time complexity -> O(N+E)
Space Complexity -> O(N+E)+O(N)+O(N)
*/


#include<bits/stdc++.h>
using namespace std;


void findTopoSort( vector<int> &vis ,int node, stack<int> &st, vector<int> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            findTopoSort(vis, it, st, adj );
        }
    }

    st.push(node);
}


void revDFS(int node, vector<int> &vis, vector<int> transpose[]){
    cout<<node<<" ";
    vis[node] = 1;
    for(auto it: transpose[node]){
        if(!vis[it]){
            revDFS(it, vis, transpose);
        }
    }
}

void findSCC(int n, vector<int> adj[]){ // Function for finding strongly connected components
    vector<int> vis(n+1, 0);
    stack<int> st;

    for(int i=1;i<=n;i++){ // First step
        if(!vis[i]){
            findTopoSort(vis, i, st, adj);
        }
    }

    // Second step

    vector<int> transpose[n+1];
    
    for(int i=1;i<=n;i++){
        vis[i] = 0;
        for(auto it: adj[i]) {
            transpose[it].push_back(i);
        }
    }

    // Third step

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cout<<"SCC: ";
            revDFS(node, vis, transpose);
            cout<<endl;
        }
    }

}

void adjList(int n, int m){
    vector<int> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v;
        cout<<"Enter two nodes: "<<endl;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    findSCC(n, adj);
}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}