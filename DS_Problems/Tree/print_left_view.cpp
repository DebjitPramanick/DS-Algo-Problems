#include <bits/stdc++.h>
using namespace std;

// Left view of a binary tree is the set of nodes 
// visible when the tree is viewed from the left. 
// Given a binary tree, print the left view of it. 
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

    void displayLeftView(){
        queue<Node *> q;
        map<int, int> mp;
        map<Node *, int> mpt;
        int vd = 0; // Vertical distances of nodes
        mpt[root] = vd; // Root's vertical distance is 0
        q.push(root);

        while(!q.empty()){
            Node *fr = q.front();
            q.pop();
            vd = mpt[fr];
            if(mp.count(vd)==0) mp[vd] = fr->data;

            if(fr->left){
                mpt[fr->left] = vd+1;
                q.push(fr->left);
            }

            if(fr->right){
                mpt[fr->right] = vd+1;
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
    t.displayLeftView();

}