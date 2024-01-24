#include <bits/stdc++.h>
using namespace std;

/*
Leaf traversal is sequence of leaves traversed from left to right. 
The problem is to check if leaf traversals of two given Binary 
Trees are same or not.
Expected time complexity O(n). Expected auxiliary space O(h1 + h2) 
where h1 and h2 are heights of two Binary Trees.
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
};

void checkSameLeaf(Node *h1, Node *h2)
{
    if (!h1 && !h2)
        return;

    vector<int> l1, l2;
    bool flag = true;

    queue<Node*> q;
    q.push(h1);

    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *fr = q.front();
            q.pop();
            if (!fr->left and !fr->right)
                l1.push_back(fr->data);
            if (fr->left)
                q.push(fr->left);
            if (fr->right)
                q.push(fr->right);
        }
    }

    q.push(h2);

    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *fr = q.front();
            q.pop();
            if (!fr->left and !fr->right)
                l2.push_back(fr->data);
            if (fr->left)
                q.push(fr->left);
            if (fr->right)
                q.push(fr->right);
        }
    }

    if (l1.size() == l2.size())
    {
        for (int i = 0; i < l1.size(); i++)
        {
            if (l1[i] != l2[i])
            {
                flag = false;
                break;
            }
        }
    }
    else
        flag = false;

    if (!flag)
        cout << "Not same" << endl;
    else
        cout << "Same" << endl;
}

int main()
{
    Tree t1(1);
    Tree t2(1);

    t1.insert(2);
    t1.insert(3);
    t1.insert(4);
    t1.insert(5);
    t1.insert(6);
    t1.insert(7);

    t2.insert(3);
    t2.insert(2);
    t2.insert(4);
    t2.insert(5);
    t2.insert(6);
    t2.insert(7);

    t1.inorder(t1.root);
    cout << endl;
    t2.inorder(t2.root);
    cout << endl;
    checkSameLeaf(t1.root, t2.root);
}