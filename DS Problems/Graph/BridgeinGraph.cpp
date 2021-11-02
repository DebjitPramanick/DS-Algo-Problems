#include<bits/stdc++.h>
using namespace std;


void findBridges(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer,vector<int> adj[]){
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(auto it: adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            findBridges(it, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                cout<<node<<" - "<<it<<endl;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
    }
}


void createNodes(int n, int m){

    vector<int> adj[n];
    
    for(int i=1;i<=m;i++){
        int u, v;
        cout << "Enter value of u (1st node): ";
        cin >> u;
        cout << "Enter value of v (2nd node): ";
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n ,-1); // Array for storing time of insertions
    vector<int> low(n, -1); // Array for storing lowest time of insertions for all adjacent nodes
    vector<int> vis(n, 0);
    int timer = 0;

    for(int i=0; i<n;i++){
        if(!vis[i]){
            findBridges(i, -1, vis, tin, low, timer, adj);
        }
    }

}


int main()
{
    int n, m;
    cout << "Enter value of n (no. of nodes): ";
    cin >> n;
    cout << "Enter value of m (no. of edges): ";
    cin >> m;

    createNodes(n,m);

}