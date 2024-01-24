/*
Cloen graph.
1. Create a deep copy of given graph
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    vector<Node *> neighbours;
    Node(){
        val = 0;
        neighbours = vector<Node *> ();
    }
    Node(int _val){
        val = _val;
        neighbours = vector<Node *> ();
    }
    Node(int _val, vector<Node *> _neighbours){
        val = _val;
        neighbours = _neighbours;
    }
};

void dfs(Node *node, Node *copy, vector<Node*> &vis){
    vis[copy->val] = copy;
    for(auto it:  node->neighbours){
        if(vis[it->val]==NULL){
            Node *newNode = new Node(it->val);
            copy->neighbours.push_back(newNode);
            dfs(it, newNode, vis);
        }
        else copy->neighbours.push_back(vis[it->val]);
    }
}


Node* cloneGraph(Node *node){
    if(!node) return NULL;
    vector<Node*> vis(1000, NULL);
    Node *copy = new Node(node->val);
    dfs(node, copy, vis);
    return copy;
}