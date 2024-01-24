#include <bits/stdc++.h>
using namespace std;

/*
Convert a Given Binary Tree into a Sum Tree
*/


struct Node{
    int data;
    Node *left;
    Node *right;
};

class Tree{
    public:

    Node *root;

    Tree(int val){
        root->data = val;
        root->right = root->left = NULL;
    }

    void insert(int val){
        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            Node *tp = q.front();
            q.pop();
            if(tp->left){
                q.push(tp->left);
            }
            else{
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->left = newNode;
                break;
            }
            if(tp->right){
                q.push(tp->right);
            }
            else{
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->right = newNode;
                break;
            }
        }
    }

    void inorder(Node *head){
        if(!head) return;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }

    int convertUtils(Node *node){

        if(!node) return 0;

        int left = convertUtils(node->left);
        int right = convertUtils(node->right);

        int real = node->data;
        node->data = left+right;
        return real+left+right;
    }

    void convert(){
        if(!root) cout<<"Valid"<<endl;
        convertUtils(root);
    }
};

int main(){
    Tree t(10);
    t.insert(-2);
    t.insert(6);
    t.insert(8);
    t.insert(-4);
    t.insert(7);
    t.insert(5);

    t.inorder(t.root);
    t.convert();
    cout<<endl;
    t.inorder(t.root);
}