#include <bits/stdc++.h>
using namespace std;

// Top view of a binary tree is the set of nodes 
// visible when the tree is viewed from the top. 
// Given a binary tree, print the top view of it. 
// The output nodes can be printed in any order.

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

    void displayTopView(){
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        mp[0] = root->data;
        q.push(make_pair(root, 0));

        while(!q.empty()){
            Node *fr = q.front().first;
            int hd = q.front().second; // Horizontal distances of nodes from toppest node
            
            cout<<hd<<fr->data<<endl;
            q.pop();

            if(mp.count(hd) == 0) mp[hd] = fr->data;
            if(fr->left) q.push(make_pair(fr->left, hd-1));
            if(fr->right) q.push(make_pair(fr->right, hd+1));
        }

        for(auto it: mp) cout<<it.second<<" ";
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
    t.displayTopView();

}