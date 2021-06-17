#include<bits/stdc++.h>
using namespace std;

// Time complexity -> O(4a) [ a => Alpha] == Almost constant time complexity

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

int findPar(int u, vector<int> &parent){
    if(u == parent[u]) return u;
    return findPar(parent[u], parent);
}

void makeUnion(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findPar(parent[u], parent);
    v = findPar(parent[v], parent);

    if(rank[u] < rank[v]) parent[u] = v;
    else if(rank[v] < rank[u]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void createMST(int n, vector<node> edges){
    vector<int> parent(n);
    for(int i=1;i<=n;i++) parent[i] = i;
    vector<int> rank(n,0);

    int cost = 0;
    vector<pair<int, int>> mst;

    for(auto it: edges){
        if(findPar(it.v, parent) != findPar(it.u, parent)){
            cost += it.wt;
            mst.push_back({it.u, it.v});
            makeUnion(it.u, it.v, parent, rank);
        }
    }

    cout<<cost<<endl;

    for(auto it: mst) cout << it.first << " - "<< it.second << endl;
}

bool comparator(node a, node b){
    return a.wt<b.wt;
}

void createEdges(int n, int m){

    vector<node> edges;
    
    for(int i=1;i<=m;i++){
        int u, v, wt;
        cout << "Enter value of u (1st node): ";
        cin >> u;
        cout << "Enter value of v (2nd node): ";
        cin >> v;
        cout << "Enter value of wt (Edge weight): ";
        cin >> wt;

        edges.push_back(node(u,v,wt));
    }

    sort(edges.begin(), edges.end(), comparator);
    createMST(n, edges);

}

int main()
{
    int n, m;
    cout << "Enter value of n (no. of nodes): ";
    cin >> n;
    cout << "Enter value of m (no. of edges): ";
    cin >> m;

    createEdges(n,m);

}