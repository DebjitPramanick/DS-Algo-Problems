#include <bits/stdc++.h>
using namespace std;

// Given a Binary Tree, find its Boundary Traversal. The traversal 
// should be in the following order: 

// Left boundary nodes: defined as the path from the root to the left-most 
// node ie- the leaf node you could reach when you always travel preferring 
// the left subtree over the right subtree. 

// Leaf nodes: All the leaf nodes except for the ones that are part of left 
// or right boundary.

// Reverse right boundary nodes: defined as the path from the right-most node 
// to the root. The right-most node is the leaf node you could reach when you 
// always travel preferring the right subtree over the left subtree. Exclude 
// the root from this as it was already included in the traversal of left 
// boundary nodes.

// Note: If the root doesn't have a left subtree or right subtree, then the root 
// itself is the left or right boundary. 

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Node *root = new Node();

    Tree(int val)
    {
        root->data = val;
        root->right = root->left = NULL;
    }

    void insert(int val)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *tp = q.front();
            q.pop();
            if (tp->left)
            {
                q.push(tp->left);
            }
            else
            {
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->left = newNode;
                break;
            }
            if (tp->right)
            {
                q.push(tp->right);
            }
            else
            {
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->right = newNode;
                break;
            }
        }
    }

    void inorder(Node *head)
    {
        if (!head)
            return;
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }

    void traverseLeft(Node *node, vector<int> &res){
        if(!node) return;
        if(node->left){
            res.push_back(node->data);
            traverseLeft(node->left, res);
        }
        else if(node->right){
            res.push_back(node->data);
            traverseLeft(node->right, res);
        }
    }

    void traverseRight(Node *node, vector<int> &res){
        if(!node) return;
        if(node->right){
            res.push_back(node->data);
            traverseRight(node->right, res);
        }
        else if(node->left){
            res.push_back(node->data);
            traverseRight(node->left, res);
        }
    }

    void traverseLeaves(Node *node, vector<int> &res){
        if(!node) return;
        traverseLeaves(node->left, res);
        if(!node->left and !node->right){
            res.push_back(node->data);
        }
        traverseLeaves(node->right, res);
    }

    void boundaryTraversal(){
        if(!root) return;
        vector<int> res;
        res.push_back(root->data);
        traverseLeft(root->left, res); // Traverse  root to left most nodes
        traverseLeaves(root->left, res); // Traverse left leaf nodes
        traverseLeaves(root->right, res); // Traverse right leaf nodes
        traverseRight(root->right, res); // Traverse from right most node to root

        for(auto it: res){
            cout<<it<<" ";
        }
    }
};

int main()
{
    Tree t(1);
    for (int i = 2; i < 8; i++)
    {
        t.insert(i);
    }

    t.inorder(t.root);
    cout << endl;
    t.boundaryTraversal();

}