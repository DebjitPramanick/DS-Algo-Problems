#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> ppi;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

class Graph{
    int m = 0;
    int n = 0;
    vector<vector<int>> graph;
    vector<node> edges;

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
            cin>>wt;
            graph[u].push_back(v);
            graph[v].push_back(u);
            edges.push_back(node(u, v, wt));
            cout<<"-------"<<endl;
        }
    }

    void solve();
};


void Graph::solve(){
    vector<int> color(n+1, -1);
    int cn = 0;

    vector<int> av(n+1, 0);

    for(int i=1;i<=n;i++){
        for(auto it: graph[i]){
            if(color[it]!=-1){
                av[color[it]] = 1;
            }
        }

        int cr = 0;
        for(cr = 0; cr<n;cr++){
            if(!av[cr]) break;
        }

        color[i] = cr;
        cn = min(cn, cr+1);

        for(auto it: graph[i]){
            if(color[it]!=-1){
                av[color[it]] = 0;
            }
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
    g.solve();
}