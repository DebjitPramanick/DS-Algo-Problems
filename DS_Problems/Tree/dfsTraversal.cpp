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


    void inorder(Node *node){
        if(node == NULL) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    void postorder(Node *node){
        if(node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
        
    }

    void preorder(Node *node){
        if(node == NULL) return;
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorderNormal(){
        if(root == NULL) return;
        stack<Node *> s;
        Node *cur = root;
        while(true){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty()) break;
            cur = s.top();
            s.pop();
            cout<<cur->data<<" ";
            cur = cur->right;
        }

    }


    void postorderNormal(){
        if(root == NULL) return;
        stack<Node *> s1, s2;
        Node *cur = root;
        s1.push(root);
        while(!s1.empty()){
            Node *cur = s1.top();
            s1.pop();
            s2.push(cur);
            if(cur->left) s1.push(cur->left);
            if(cur->right) s1.push(cur->right);
        }
        while(!s2.empty()){
            Node *cur = s2.top();
            s2.pop();
            cout<<cur->data<<" ";
        }
    }


    void preorderNormal(){
        if(root == NULL) return;
        stack<Node *> s;
        s.push(root);
        while(!s.empty()){
            Node *cur = s.top();
            s.pop();
            cout<<cur->data<<" ";
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
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

    cout<<"Recursive approach: "<<endl;
    t.inorder(root);
    cout<<endl;
    t.preorder(root);
    cout<<endl;
    t.postorder(root);
    cout<<endl;

    cout<<"Non-recursive approach: "<<endl;
    t.inorderNormal();
    cout<<endl;
    t.preorderNormal();
    cout<<endl;
    t.postorderNormal();
    cout<<endl;
}