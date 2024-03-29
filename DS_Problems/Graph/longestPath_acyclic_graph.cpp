#include<bits/stdc++.h>
using namespace std;


void findTopoSort( int vis[] ,int node, stack<int> &st, vector<pair<int,int>> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it.first]){
            findTopoSort(vis, it.first, st, adj );
        }
    }

    st.push(node);
}

void findLongestPath(int n, vector<pair<int,int>> adj[], int src){
    int vis[n] = {0};
    stack<int> st;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            findTopoSort(vis, i, st, adj);
        }
    }

    int dis[n];
    for(int i=1;i<=n;i++){
        dis[i] = INT_MIN;
    }
    dis[src] = 0;

    while(!st.empty()){
        int fn = st.top();
        st.pop();
        if(dis[fn] != INT_MIN){
            for(auto i: adj[fn]){
                if(dis[fn] + i.second > dis[i.first]){
                    dis[i.first] = dis[fn] + i.second;
                }
            }
        }
    }

    cout<<"The longest path of each node are: ";
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}

void adjList(int n, int m){
    vector<pair<int,int>> adj[n+1];
    
    for(int i=1;i<=m;i++){
        int u, v, wt;
        cout<<"Enter nodes and edge weight: "<<endl;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    findLongestPath(n, adj, 1);
}

int main(){
    int n, m;
    cout<<"Enter no. of nodes and edges: "<<endl;
    cin >> n >> m;
    adjList(n, m);
}