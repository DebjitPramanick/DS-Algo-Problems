#include <bits/stdc++.h>
using namespace std;

// Given a binary tree and a node, print all
// cousins of given node. Note that siblings
// should not be printed.

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

    int getLevel(Node *head, Node *node, int level){
        if (head == NULL) return 0;
        if (head == node) return level;

        int downlevel = getLevel(head->left,
                                 node, level + 1);
        if (downlevel != 0) return downlevel;

        return getLevel(head->right, node, level + 1);
    }

    void printGivenLevel(Node *head, Node *node, int level){
        if (head == NULL || level < 2)
            return;

        if (level == 2)
        {
            if (head->left == node || head->right == node)
                return;
            if (head->left)
                cout << head->left->data << " ";
            if (head->right)
                cout << head->right->data;
        }

        else if (level > 2)
        {
            printGivenLevel(head->left, node, level - 1);
            printGivenLevel(head->right, node, level - 1);
        }
    }

    void printCousins(Node *node)
    {
        int level = getLevel(root, node, 1);

        printGivenLevel(root, node, level);
    }
};

int main()
{
    Tree t(1);
    for (int i = 2; i < 14; i++)
    {
        t.insert(i);
    }

    t.inorder(t.root);
    cout << endl;
    t.printCousins(t.root->right->left->left);
}