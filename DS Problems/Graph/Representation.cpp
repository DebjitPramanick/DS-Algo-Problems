#include <bits/stdc++.h>
using namespace std;

void adjMatrix(int n, int m)
{
    int adj[n + 1][n + 1];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter value of u (1st node): ";
        cin >> u;
        cout << "Enter value of v (2nd node): ";
        cin >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adj[i][j] << "  ";
        }

        cout << "\n";
    }
}

void adjList(int n, int m){

    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u, v;
        cout << "Enter value of u (1st node): ";
        cin >> u;
        cout << "Enter value of v (2nd node): ";
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i < n+1 ;i++){
        
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it){
            cout << *it << " ";
        }
        
        cout << "\n";

    }
}

int main()
{
    cout << "Representation of graph: "
         << "\n";

    int n, m;
    cout << "Enter value of n (no. of nodes): ";
    cin >> n;
    cout << "Enter value of m (no. of edges): ";
    cin >> m;

    adjList(n,m);

}