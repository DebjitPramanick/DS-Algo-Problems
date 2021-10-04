#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, write a function that returns true if the 
tree satisfies below property. For every node, data value must 
be equal to sum of data values in left and right children. 
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

    void checkChildrenSum(){
        queue<Node *> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            Node *tp = q.front();
            q.pop();
            if(tp->left and tp->right){
                int sum = tp->left->data + tp->right->data;
                if(sum != tp->data) {
                    flag = false;
                    break;
                }
            }
            else if(tp->left){
                int sum = tp->left->data + 0;
                if(sum != tp->data) {
                    flag = false;
                    break;
                }
            }
            else if(tp->right){
                int sum = tp->right->data + 0;
                if(sum != tp->data) {
                    flag = false;
                    break;
                }
            }

            if(tp->left) q.push(tp->left);
            if(tp->right) q.push(tp->right);
        }

        if(!flag) cout<<"Not valid"<<endl;
        else cout<<"Valid"<<endl;
    }

    
};

int main(){
    Tree t(9);
    t.insert(3);
    t.insert(6);
    t.insert(2);
    t.insert(10);
    t.insert(5);
    t.insert(1);

    t.checkChildrenSum();
    t.inorder(t.root);
}