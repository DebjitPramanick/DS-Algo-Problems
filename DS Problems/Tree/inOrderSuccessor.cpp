// Inorder successor in BST

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root, *head, *newnode, *temp;

class BST
{
public:
    Node *create(int v)
    {
        newnode = new Node();
        newnode->data = v;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    void insert(Node *&node, int v)
    {
        if (node == NULL)
        {
            node = create(v);
            return;
        }
        if (v < node->data)
            insert(node->left, v);
        else
            insert(node->right, v);
    }

    void inorder()
    {
        if (root == NULL)
            return;

        stack<Node *> s;
        Node *cur = root;

        while (true)
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty())
                break;
            cur = s.top();
            s.pop();
            cout << cur->data << " ";
            cur = cur->right;
        }
    }

    Node *FindMin(Node *node){
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }

    Node *Find(Node *node,int v)
    {
        if (root == NULL)
            return NULL;
        Node *cur = root;
        while (cur)
        {
            if (cur->data == v) return cur;
            if (v < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return NULL;
    }

    Node *getSuccessor(Node *root, int data){
        Node *cur = Find(root, data);
        if(cur == NULL) return NULL;
        if(cur->right != NULL) {
            return FindMin(cur->right);
        }
        else{
            Node *successor = NULL;
            Node *ancestor = root;
            while(ancestor != cur){
                if(cur->data < ancestor->data){
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
                else{
                    ancestor = ancestor->right;
                }
            }
            return successor;
        }
    }
};

int main(){
    BST t;
    int n, del;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter node: ";
        cin >> val;
        t.insert(root, val);
    }

    t.inorder();
    cout << endl;
    Node *res = t.getSuccessor(root, 5);
    cout<<endl;
    cout<<res->data<<endl;
}
