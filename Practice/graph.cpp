#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

class Graph{
    int m = 0;
    int n = 0;
    vector<vector<int>> graph;

    public:
    Graph(int _m, int _n){
        m = _m; //Edges
        n = _n; // Nodes
        graph.resize(n+1);
        cout<<"Enter nodes: "<<endl;

        for(int i=1;i<=m;i++){
            int u, v, wt;
            cin>>u;
            cin>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cout<<"-------"<<endl;
        }
    }

    void findBridge();
};

void dfs(int node, int parent, vector<int> &low, vector<int> &tin, int timer, vector<int> &vis, vector<vector<int>> graph){
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(auto it: graph[node]){
        if(!vis[it]){
            dfs(it, node, low, tin, timer, vis, graph);
            low[node] = min(low[it], low[node]);
            if(low[it]>tin[node]){
                cout<<node<<" - "<<it<<endl;
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
}

void Graph::findBridge(){
   vector<int> low(n+1, -1), tin(n+1, -1), vis(n+1, 0);
   int timer = 0;

   for(int i=1;i<=n;i++){
       if(!vis[i]){
           dfs(i, -1, low, tin, timer, vis, graph);
       }
   }
}


int main(){
    int m, n;
    cout<<"Enter values: "<<endl;
    cin>>m;
    cin>>n;
    Graph g(m, n);
    // g.display();
    g.findBridge();
}