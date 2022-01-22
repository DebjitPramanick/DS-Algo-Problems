#include <bits/stdc++.h>
using namespace std;

void findMSTPrim(int n, vector<pair<int, int>> adj[])
{
    int key[n];
    int parent[n];
    bool mstSet[n];

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for (int i = 1; i <= n; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    key[1] = 0;
    parent[1] = -1;
    pq.push({0, 1});

    for (int i = 1; i <= n - 1; i++)
    {
        // This is priority queue implementation
        // Entire time complexity is: O(NlogN)

        int u = pq.top().second;
        pq.pop();
        
        mstSet[u] = true;

        // Finding the adjacent nodes with smaller edge weight ----------

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (mstSet[v] == false && wt < key[v])
            {
                parent[v] = u;
                key[v] = wt;
                if(key[v]==wt){
                    pq.push({key[v], v});
                }
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
