#include <bits/stdc++.h>
using namespace std;

/*

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

    void inorder(Node *head)
    {
        if (!head)
            return;
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }

    bool isSibling(Node *node, int a, int b)
    {
        if (!node || !node->left || !node->right) return 0;

        return ((node->left->data == a && node->right->data == b) ||
                (node->left->data == b && node->right->data == a) ||
                isSibling(node->left, a, b) ||
                isSibling(node->right, a, b));
    }

    int level(Node *node, int val, int lev)
    {
        if (!node) return 0;
        if (node->data == val) return lev;
        int l = level(node->left, val, lev + 1);
        if (l != 0)
            return l;

        return level(node->right, val, lev + 1);
    }

    int isCousin(int a, int b)
    {
        if ((level(root, a, 1) == level(root, b, 1)) && !isSibling(root, a, b))
            return 1;
        else return 0;
    }
};

int main()
{
    Tree t(1);
    for (int i = 2; i < 8; i++)
    {
        t.insert(i);
    }

    cout<<t.isCousin(5, 6)<<endl;
    t.inorder(t.root);
}