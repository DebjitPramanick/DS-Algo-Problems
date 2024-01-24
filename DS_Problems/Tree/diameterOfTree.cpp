#include <bits/stdc++.h>
using namespace std;

// Find diameter of tree

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

    int findDiameter(Node *node){ // Time -> O(n2)
        if(!node) return 0;

        int lh = height(node->left);
        int rh = height(node->right);
        int ld = findDiameter(node->left);
        int rd = findDiameter(node->right);

        return max(lh+rh+1, max(rd, ld));
    }

    int height(Node *node){
        if(!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int findDm(Node *node, int* h){ // Time -> O(n)
        
        int lh = 0, rh = 0;
        int ld = 0, rd = 0;
        
        if(!node) {
            *h = 0;
            return 0;
        }

        ld = findDm(node->left, &lh);
        rd = findDm(node->right, &rh);
        *h = max(lh, rh) + 1;
        return max(lh + rh + 1, max(ld, rd));
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
    int ans = t.findDiameter(t.root);
    cout<<ans<<endl;
    int height = 0;
    cout<<t.findDm(t.root, &height);
}