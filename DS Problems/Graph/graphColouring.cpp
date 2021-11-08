/*
Graph coloring problem is to assign colors to certain elements 
of a graph subject to certain constraints. 
Vertex coloring is the most common graph coloring problem. The 
problem is, given m colors, find a way of coloring the vertices 
of a graph such that no two adjacent vertices are colored using 
same color. The other graph coloring problems like Edge Coloring 
(No vertex is incident to two edges of same color) and Face Coloring 
(Geographical Map Coloring) can be transformed into vertex coloring. 

Chromatic Number: The smallest number of colors needed to color a 
graph G is called its chromatic number. For example, the following 
can be colored minimum 2 colors.


For this problem:
1. Use minimum number of colors
2. No two adjacent vertices are colored using same color
3. Color all nodes

*/

#include<bits/stdc++.h>
using namespace std;


void colourGraph(vector<int> adj[], int n){
    vector<int> colour(n, -1);
    vector<int> available(n, 0);

    colour[0] = 0;
    int cn = 0; // Chromatic number

    for(int i=0;i<n;i++){
        for(auto it: adj[i]){
            if(colour[it]!=-1){ // If adjacent node is coloured
                available[colour[it]] = 1; // Mark colurs as already available in graph
            }
        }

        int cr;
        for(cr=0;cr<n;cr++){
            if(!available[cr]) break;
        }

        colour[i] = cr;
        cn = max(cn, cr+1);

        // Resetting

        for(auto it: adj[i]){
            if(colour[i]!=-1){
                available[colour[it]] = 0;
            }
        }
    }

    cout<<"Chromatic number is: "<<cn<<endl;
    for(int i=0;i<n;i++) cout<<colour[i]<<" ";
}


void adjList(int n, int m){
    vector<int> adj[n];
    
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    colourGraph(adj, n);
}

int main(){
    int n, m;
    cin >> n >> m;
    adjList(n, m);
}