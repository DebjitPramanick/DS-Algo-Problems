#include <bits/stdc++.h>
using namespace std;

void findMSTPrim(int n, vector<pair<int, int>> adj[])
{
    int key[n];
    int parent[n];
    bool mstSet[n];

    for (int i = 1; i <= n; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i <= n - 1; i++)
    {
        int mini = INT_MAX, u;

        // Finding the minimal

        // This for loop is used for brute force approach
        // We can replace this process with a priority queue for lesser time complexity

        for (int v = 1; v <= n; v++)
            if (mstSet[v] == false && key[v] < mini)
                mini = key[v], u = v;
        
        mstSet[u] = true;

        // Finding the adjacent nodes with smaller edge weight
        

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (mstSet[v] == false && wt < key[v])
            {
                parent[v] = u, key[v] = wt;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << " - " << i << "\n";
    }
}

void adjList(int n, int m)
{

    vector<pair<int, int>> adj[n + 1];

    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cout << "Enter value of u (1st node): ";
        cin >> u;
        cout << "Enter value of v (2nd node): ";
        cin >> v;
        cout << "Enter value of wt (Edge weight): ";
        cin >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    findMSTPrim(n, adj);
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

    adjList(n, m);
}