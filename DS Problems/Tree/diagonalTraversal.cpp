#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, print the level order traversal in 
such a way that first two levels are printed from left to 
right, next two levels are printed from right to left, 
then next two from left to right and so on. So, the problem 
is to reverse the direction of level order traversal of 
binary tree after every two levels.
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

    void diagonalTraversal(){
        vector<int> ans;

        queue<Node*> q;
        Node* node = root;
        while(node){
            ans.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) node = node->right;
            else{
                if(!q.empty()){
                    node = q.front();
                    q.pop();
                }
                else node = NULL;
            }
        }

        for(auto it: ans){
            cout<<it<<" ";
        }
    }


};

int main(){
    Tree t(1);
    for(int i=2;i<=7;i++) t.insert(i);
    t.diagonalTraversal();
}