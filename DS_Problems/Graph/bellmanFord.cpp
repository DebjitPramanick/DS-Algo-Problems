#include<bits/stdc++.h>
using namespace std;

/*
Time complexity -> O(N-1) x O(E)
Space complexity -> O(N)
*/

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

void findBellmanFordPath(int n, vector<node> edges){

    int src;
    cout<<"Enter source: "<<endl;
    cin>>src;

    vector<int> dis(n, INT_MAX);
    dis[src] = 0;

    for(int i=1;i<=n-1;i++){ // Relaxation occurs for all nodes in the graph for n-1 times
        for(auto it: edges){  
            if(dis[it.u] + it.wt < dis[it.v]){ 
                dis[it.v] = dis[it.u] + it.wt;
            } 
        }
    }

    // For checking negative cycle relax the nodes for one more time

    int fl = 0;
    for(auto it: edges){
        if(dis[it.u]+it.wt < dis[it.v]){
            cout<<"Negative cycle."<<endl;
            fl = 1;
            break;
        }
    }

    if(!fl){
        for(int i=0;i<n;i++){
            cout<<i<<" "<<dis[i]<<endl;
        }
    }
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

    findBellmanFordPath(n , edges);

}

int main(){
    int n, m;
    cout << "Enter value of n (no. of nodes): ";
    cin >> n;
    cout << "Enter value of m (no. of edges): ";
    cin >> m;

    createEdges(n,m);
}