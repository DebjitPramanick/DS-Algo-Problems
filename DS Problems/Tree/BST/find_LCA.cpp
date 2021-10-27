#include <bits/stdc++.h>
using namespace std;

/*
Given values of two values n1 and n2 in a Binary Search Tree, 
find the Lowest Common Ancestor (LCA). You may assume that 
both the values exist in the tree. 
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

    Node *lcaUtils(Node *node, int n1, int n2){
        if(!node) return NULL;
        if(node->data > n1 and node->data < n2) return node;
        else if(node->data > n1 and node->data > n2)
            return lcaUtils(node->left, n1, n2);
        return lcaUtils(node->right, n1, n2);
    }


    void LCA(int n1, int n2){
        if(!root) return;
        Node *ans = lcaUtils(root, n1, n2);
        if(ans) cout<<ans->data<<endl;
        else cout<<"Not found."<<endl;
    }


    
};

int main(){
    Tree t(20);
    t.insert(8);
    t.insert(22);
    t.insert(4);
    t.insert(12);

    t.LCA(8, 22);

}