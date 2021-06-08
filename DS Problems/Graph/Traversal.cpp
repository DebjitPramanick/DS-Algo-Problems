#include <bits/stdc++.h>
using namespace std;

void dfsofGraph(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsofGraph(it, vis, adj, dfs);
        }
    }
}

void DFS(int n, vector<int> adj[])
{
    vector<int> dfs;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfsofGraph(i, vis, adj, dfs);
        }
    }

    for (auto i : dfs)
    {
        cout << i << " ";
    }
}

void BFS(int n, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {

        if (vis[i] == 0)
        {

            // BFS Code

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

    for (auto i : bfs)
    {
        cout << i << " ";
    }
}

void adjList(int n, int m)
{

    vector<int> adj[n + 1];

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cout << "Enter value of u (1st node): ";
        cin >> u;
        cout << "Enter value of v (2nd node): ";
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(n, adj);
}

int main()
{
    cout << "Traversal of graph: "
         << "\n";

    int n, m;
    cout << "Enter value of n (no. of nodes): ";
    cin >> n;
    cout << "Enter value of m (no. of edges): ";
    cin >> m;

    adjList(n, m);
}