#include <bits/stdc++.h>
using namespace std;

// Given a binary tree and a node, print all
// duplicate trees

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

    string helper(Node *node, vector<Node *> &ans, unordered_map<string, int> &mp){
        if(!node) return "";
        string res = to_string(node->data) + " ";
        res += helper(node->left, ans, mp);
        res += helper(node->right, ans, mp);
        if(mp.count(res) and mp[res]==1){
            ans.push_back(node);
            mp[res]++;
        }
        else if(!mp.count(res)) mp[res] = 1;
        return res;
    }

    void findDuplicates(){
        if(!root) return;
        vector<Node *> ans;
        unordered_map<string, int> mp;
        helper(root, ans, mp);
        for(auto it: ans){
            cout<<it->data<<" ";
        }
    }
};

int main()
{
    Tree t(1);
    t.insert(2);
    t.insert(2);
    t.insert(4);
    t.insert(5);
    t.insert(4);
    t.insert(7);

    t.inorder(t.root);
    cout << endl;
    t.findDuplicates();
}