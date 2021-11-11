#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printVertexCover()
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            for (auto it : adj[i])
            {
                // Add the vertices (u, v) to the result set.
                // We make the vertex u and v visited so that
                // all edges from/to them would be ignored
                if (!vis[it])
                {
                    vis[it] = 1;
                    vis[i] = 1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (vis[i])
            cout << i << " ";
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();

    return 0;
}