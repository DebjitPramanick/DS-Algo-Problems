#include <bits/stdc++.h>
using namespace std;

// Bottom view of a binary tree is the set of nodes 
// visible when the tree is viewed from the bottom. 
// Given a binary tree, print the bottom view of it. 
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

    void displayBottomView(){
        queue<Node *> q;
        map<int, int> mp;
        map<Node *, int> mpt;
        int hd = 0;
        mpt[root] = hd;
        q.push(root);

        while(!q.empty()){
            Node *fr = q.front();
            q.pop();
            hd = mpt[fr];
            mp[hd] = fr->data;

            if(fr->left){
                mpt[fr->left] = hd-1;
                q.push(fr->left);
            }

            if(fr->right){
                mpt[fr->right] = hd+1;
                q.push(fr->right);
            }
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
    t.displayBottomView();

}