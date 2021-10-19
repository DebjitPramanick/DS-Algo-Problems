#include <bits/stdc++.h>
using namespace std;

// Given a binary tree with distinct nodes
// (no two nodes have the same have data values). 
// The problem is to print the path from root to a
// given node x. If node x is not present then print “No Path”.



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

    bool hasPath(Node *node, vector<int> &path, int x){
        if(!node) return false;
        path.push_back(node->data);
        if(node->data == x) return true;
        if(hasPath(node->left, path, x)||hasPath(node->right, path, x)) return true;
        path.pop_back();
        return false;
    }

    void getPath(Node *node){
        if(!root) cout << "No path";
        vector<int> path;
        if(hasPath(root, path, node->data)){
            for(int i=0;i<path.size();i++){
                if(i!=path.size()-1)
                    cout<<path[i]<<" -> ";
                else cout<<path[i];
            }
        }
        else cout<<"No path";
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
    t.getPath(t.root->right->left);
}