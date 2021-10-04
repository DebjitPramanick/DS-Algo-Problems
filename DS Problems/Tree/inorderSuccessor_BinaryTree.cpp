#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree and a node, we need to write a program to find 
inorder successor of this node.Inorder Successor of a node in binary 
tree is the next node in Inorder traversal of the Binary Tree. 
Inorder Successor is NULL for the last node in Inorder traversal.
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

    void storeInorder(Node *node, vector<int> &temp){
        if(!node) return;
        storeInorder(node->left, temp);
        temp.push_back(node->data);
        storeInorder(node->right, temp);
    }

    void findSuccessor(int target){
        vector<int> temp;
        temp.push_back(0);
        storeInorder(root, temp);
        temp.push_back(0);

        for(int i=1; i<temp.size()-1; i++){
            if(temp[i] == target and temp[i+1] != 0){
                cout<<"Successor is: "<<temp[i+1]<<endl;
            }
            else if(temp[i] == target){
                cout<<"No successor."<<endl;
            }
        }
    }

    
};

int main(){
    Tree t(1);
    for(int i=2; i<8; i++){
        t.insert(i);
    }

    t.findSuccessor(3);
    t.inorder(t.root);
}