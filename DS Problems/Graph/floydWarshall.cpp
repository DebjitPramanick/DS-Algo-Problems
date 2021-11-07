#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void findAllPairsShortestPath(vector<vector<int>> adj, int n){
    vector<vector<int>> dist = adj;

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(dist[i][j] == INF) cout<<"INF"<< "  ";
            else cout << dist[i][j] << "  ";
        }
        cout << "\n";
    }
}

void adjMatrix(int n, int m){
    vector<vector<int>> adj(n+1, vector<int> (n+1, INF));

    for (int i = 0; i < m; i++){
        int u, v, wt;
        cout << "Enter value of u (1st node): ";
        cin >> u;
        cout << "Enter value of v (2nd node): ";
        cin >> v;
        cout << "Enter weight of edge: ";
        cin >> wt;

        adj[u][v] = wt;
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++)
            cout << adj[i][j] << "  ";

        cout << "\n";
    }
    

    findAllPairsShortestPath(adj, n);
};

int main(){
    cout << "Representation of graph: "
         << "\n";

    int n, m;
    cout << "Enter value of n (no. of nodes): ";
    cin >> n;
    cout << "Enter value of m (no. of edges): ";
    cin >> m;

    adjMatrix(n,m);
}
