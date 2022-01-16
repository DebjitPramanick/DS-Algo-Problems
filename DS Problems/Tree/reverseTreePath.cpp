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

    Node *root = NULL;

    Tree(int val){
        root = new Node();
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

    Node *reverseUtil(Node *node, int k, map<int, int> &temp, int level, int &nextPos){
        if(!node) return NULL;

        if(node->data == k){ // This will execute at last when the node is found
            temp[level] = node->data;
            node->data = temp[nextPos++];
            return node;
        }

        temp[level] = node->data;

        Node* left, *right;

        left = reverseUtil(node->left, k, temp, level+1, nextPos);
        if(!left) right = reverseUtil(node->right, k, temp, level+1, nextPos);

        if(left || right) { // This will run at leaf node
            node->data = temp[nextPos++];
            return (left ? left : right);
        }

        return NULL;

    }

    void reverse_Path(int data){
        map<int, int> temp;
        int nextPos = 0;
        reverseUtil(root, data, temp, 0, nextPos);
    }

    void inorder(Node *node){
        if(!node) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);

    }
};

int main(){
    Tree t(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);

    t.reverse_Path(5);

    t.inorder(t.root);

}