#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root, *newNode;

class BST
{
public:
    Node *create(int v)
    {
        newNode = new Node();
        newNode->data = v;
        newNode->left = newNode->right = NULL;
        return newNode;
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

    void insertIterative(int v)
    {
        if (root == NULL)
        {
            root = create(v);
            return;
        }

        Node *cur = root;
        Node *parent = NULL;

        while (cur)
        {
            parent = cur;
            if (v < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (parent->data < v)
            parent->right = create(v);
        else
            parent->left = create(v);
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

    void search(int v){
        if(root == NULL) return;
        Node *cur = root;
        while(cur){
            if(cur->data == v){
                cout<<"Data found."<<endl;
                return;
            }
            if(v<cur->data) cur = cur->left;
            else cur = cur->right;
        }
        cout<<"Data not found."<<endl;
    }

};

int main()
{
    BST t;
    int n, del;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter node: ";
        cin >> val;
        t.insertIterative(val);
    }

    t.inorder();
    cout<<endl;
    cout << "Enter data to search: ";
    cin >> n;
    t.search(n);
}