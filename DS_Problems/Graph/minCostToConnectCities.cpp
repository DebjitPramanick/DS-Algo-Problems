#include <bits/stdc++.h>
using namespace std;


/*

There are n cities and there are roads in between some of the cities. 
Somehow all the roads are damaged simultaneously. We have to repair 
the roads to connect the cities again. There is a fixed cost to repair 
a particular road. Find out the minimum cost to connect all the cities 
by repairing roads. Input is in matrix(city) form, if city[i][j] = 0 
then there is not any road between city i and city j, if 
city[i][j] = a > 0 then the cost to rebuild the path between city i 
and city j is a. Print out the minimum cost to connect all the cities. 
It is sure that all the cities were connected before the roads were damaged.

*/

// Function to find out minimum valued node
// among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[]) {
  int mini = INT_MAX;
  int mini_index;
 
  // Loop through all the values of the nodes
  // which are not yet included in MST and find
  // the minimum valued one.
  for (int i = 0; i < n; i++) {
    if (mstset[i] == false && keyval[i] < mini) {
      mini = keyval[i], mini_index = i;
    }
  }
  return mini_index;
}
 
// Function to find out the MST and
// the cost of the MST.
void findcost(int n, vector<vector<int>> city) {

  int parent[n];
  int keyval[n];
  bool mstset[n];
 
  for (int i = 0; i < n; i++) 
    keyval[i] = INT_MAX, mstset[i] = false;
 
  // Start to find the MST from node 0.
  // Parent of node 0 is none so set -1.
  // key value or minimum cost to reach
  // 0th node from 0th node is 0.
  parent[0] = -1;
  keyval[0] = 0;
 
  // Find the rest n-1 nodes of MST.
  for (int i = 0; i < n - 1; i++) {
 
    // First find out the minimum node
    // among the nodes which are not yet
    // included in MST.
    int u = minnode(n, keyval, mstset);
 
    // Now the uth node is included in MST.
    mstset[u] = true;
 
    // Update the values of neighbor
    // nodes of u which are not yet
    // included in MST.
    for (int v = 0; v < n; v++) {
 
      if (city[u][v] && mstset[v] == false &&
          city[u][v] < keyval[v]) {
        keyval[v] = city[u][v];
        parent[v] = u;
      }
    }
  }
 
  // Find out the cost by adding
  // the edge values of MST.
  int cost = 0;
  for (int i = 1; i < n; i++)
    cost += city[parent[i]][i];
  cout << cost << endl;
}
 
// Utility Program:
int main() {
 
  // Input 1
  int n1 = 5;
  vector<vector<int>> city1 = {{0, 1, 2, 3, 4},
                               {1, 0, 5, 0, 7},
                               {2, 5, 0, 6, 0},
                               {3, 0, 6, 0, 0},
                               {4, 7, 0, 0, 0}};
  findcost(n1, city1);
 
  // Input 2
  int n2 = 6;
  vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0},
                               {1, 0, 1, 0, 0, 0},
                               {1, 1, 0, 0, 0, 0},  
                               {100, 0, 0, 0, 2, 2},
                               {0, 0, 0, 2, 0, 2}, 
                               {0, 0, 0, 2, 2, 0}};
  findcost(n2, city2);
 
  return 0;
}