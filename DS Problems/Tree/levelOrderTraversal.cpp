#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *root, *newnode, *temp;

class Tree{
public:
    Node *createNode(int v){
        newnode = new Node();
        newnode->data = v;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    void insertNode(int v)
    {
        if (root == NULL){
            root = createNode(v);
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty()){
            temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            else if (temp->left == NULL)
                temp->left = createNode(v);
            else if (temp->right != NULL)
                q.push(temp->right);
            else
                temp->right = createNode(v);
        }
    }

    void levelOrder(){
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);

        while (!q.empty()){
            Node *cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
        }
    }
};

int main(){
    Tree t;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cout << "Enter node: ";
        cin >> val;
        t.insertNode(val);
    }

    t.levelOrder();
}