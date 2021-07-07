#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *root, *newnode, *temp, *key, *last;

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
            else if (temp->left == NULL){
                temp->left = createNode(v);
                return;
            }
            if (temp->right != NULL)
                q.push(temp->right);
            else{
                temp->right = createNode(v);
                return;
            }
        }
    }

    void deleteDeepest(Node *node){
        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            Node *cur = q.front();
            q.pop();

            if(cur == node) {
                cur = NULL;
                delete(cur);
                return;
            };
            if(cur->left) {
                if(cur->left == node){
                    cur->left = NULL;
                    delete(cur->left);
                    return;
                }
                else{
                    q.push(cur->left);
                }
            };
            if(cur->right) {
                if(cur->right == node){
                    cur->right = NULL;
                    delete(cur->right);
                    return;
                }
                else{
                    q.push(cur->right);
                }
            };
        }
    }

    void deleteNode(int v){ // Double traversal
        if(root == NULL) return;
        queue<Node *> q;

        q.push(root);
        while(!q.empty()){
            key = q.front();
            q.pop();

            if(key->data == v) temp = key;
            if(key->left) q.push(key->left);
            if(key->right) q.push(key->right);
        }

        if(temp){
            int s = key->data;
            deleteDeepest(key);
            temp->data = s;
        }
    }

    void deleteNodeSingle(int v){ // Single traversal
        if(root == NULL) return;
        queue<Node *> q;

        q.push(root);
        while(!q.empty()){
            key = q.front();
            q.pop();

            if(key->data == v) temp = key;
            if(key->left) q.push(key->left);
            if(key->right) q.push(key->right);
        }

        if(temp){
            int s = key->data;
            temp->data = s;
            key = NULL;
            delete(key);
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
    int n, del;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cout << "Enter node: ";
        cin >> val;
        t.insertNode(val);
    }

    t.levelOrder();

    cout << "Enter data to delete: ";
    cin >> del;
    t.deleteNodeSingle(del);
    t.levelOrder();
}