#include <bits/stdc++.h>
using namespace std;


// Given a binary tree and an array, the task is to 
// find if the given array sequence is present as a root 
// to leaf path in given tree.

struct Node{
    int data;
    Node *left;
    Node *right;
};

class Tree{
    public:

    Node *root = new Node();

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

    bool check (int arr[], int n){
        queue<Node *> q;
        int i = 0;
        if(arr[i] != root->data) return false;

        q.push(root);

        while(!q.empty()){
            Node *f = q.front();
            q.pop();
            i++;
            if(f->left && arr[i] == f->left->data){
                q.push(f->left);
            }
            else if(f->right && arr[i] == f->right->data){
                q.push(f->right);
            }
        }

        if(i!=n) return false;
        return true;
    }

    
};

int main(){
    Tree t(1);
    for(int i=2; i<8; i++){
        t.insert(i);
    }

    t.inorder(t.root);
    int arr[] = {1, 2, 5};
    cout<<t.check(arr, 3);
}