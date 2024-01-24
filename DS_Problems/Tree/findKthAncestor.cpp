#include <bits/stdc++.h>
using namespace std;

/*
Find minimum swaps required to convert a Binary tree into Binary
Search Tree
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
    Node *root = new Node();
    Node *temp = NULL;

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

    Node *kthAncestorDFS(Node *curNode, int node, int &k)
    {
        // Base case
        if (!curNode)
            return NULL;

        if (curNode->data == node ||
            (kthAncestorDFS(curNode->left, node, k) != NULL) ||
            (kthAncestorDFS(curNode->right, node, k) != NULL))
        {
            if (k > 0)
                k--;

            else if (k == 0)
            {
                cout << endl << "Kth ancestor is: " << curNode->data;
                return NULL;
            }

            return curNode;
        }
        return NULL;
    }

};

int main()
{
    Tree t(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);

    t.inorder(t.root);
    int k = 2;
    t.kthAncestorDFS(t.root, 5, k);
}