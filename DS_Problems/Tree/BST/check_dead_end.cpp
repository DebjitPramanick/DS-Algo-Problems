#include <bits/stdc++.h>
using namespace std;

/*
Check for dead end in BST.
Here Dead End means, we are not able to insert any element after that node.
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Node *root;

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

    Node *newNode(int data)
    {
        Node *node = new Node();
        node->data = data;
        node->left = node->right = NULL;
        return (node);
    }

    void customTree()
    {
        root->left = newNode(5);
        root->right = newNode(9);
        root->left->left = newNode(2);
        root->left->right = newNode(7);
        root->left->left->left = newNode(1);
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void storeInorder(Node *node, unordered_set<int> &all_nodes,
                      unordered_set<int> &leaf_nodes)
    {
        if (!node)
            return;
        all_nodes.insert(node->data);
        if (!node->left and !node->right)
        {
            leaf_nodes.insert(node->data);
        }

        storeInorder(node->left, all_nodes, leaf_nodes);
        storeInorder(node->right, all_nodes, leaf_nodes);
    }

    bool checkDeadEnd()
    {
        unordered_set<int> all_nodes, leaf_nodes;
        // insert 0 in 'all_nodes' for handle case
        // if bst contain value 1
        all_nodes.insert(0);
        storeInorder(root, all_nodes, leaf_nodes);

        for (auto i = leaf_nodes.begin(); i != leaf_nodes.end(); i++)
        {
            int x = (*i);

            // Here we check first and last element of
            // continuous sequence that are x-1 & x+1
            if (all_nodes.find(x + 1) != all_nodes.end() &&
                all_nodes.find(x - 1) != all_nodes.end())
                return true;
        }

        return false;
    }
};

int main()
{
    Tree t(8);
    t.customTree();
    t.inorder(t.root);
    cout<<endl;
    cout<<t.checkDeadEnd()<<endl;
}