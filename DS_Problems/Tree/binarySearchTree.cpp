#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root, *newNode, *temp;

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

    void search(int v)
    {
        if (root == NULL)
            return;
        Node *cur = root;
        while (cur)
        {
            if (cur->data == v)
            {
                cout << "Data found." << endl;
                return;
            }
            if (v < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        cout << "Data not found." << endl;
    }

    struct Node *minValueNode(Node *node)
    {
        Node *current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == NULL)
            return root;
        else if (key < root->data) // Finding node with key
            root->left = deleteNode(root->left, key);

        else if (key > root->data) // Finding node with key
            root->right = deleteNode(root->right, key);

        else // Node found with key
        {
            if (root->left == NULL && root->right == NULL) // If key node has no right or left child
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL) // If key node has no left child
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL) // If key node has no right child
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else{ // If key node has both right and left child
                Node *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
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
    cout << endl;
    cout << "Enter data to search: ";
    cin >> n;
    t.search(n);
    cout << "Enter data to delete: ";
    cin >> n;
    t.deleteNode(root, n);
    t.inorder();
}