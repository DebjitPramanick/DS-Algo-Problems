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

    void display_reverse(){
        queue<Node *> q;
        stack<Node *> s;
        q.push(root);

        while(!q.empty()){
            Node *fr = q.front();
            q.pop();
            s.push(fr);
            if(fr->right) q.push(fr->right);
            if(fr->left) q.push(fr->left);
        }

        while(!s.empty()){
            Node *tp = s.top();
            s.pop();
            cout<<tp->data<<" ";
        }
    }

    void display_reverse_recur(){
        int h = height();
        for(int i=h;i>=1;i--) printLevel(root, i);
    }

    void printLevel(Node *node, int l){
        if(!node) return;
        if(l == 1) cout<<node->data<<" ";
        else if(l>1){
            printLevel(node->left, l-1);
            printLevel(node->right, l-1);
        }
    }

    int height(){
        int h = 0;
        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            h++;
            for(int i=0;i<sz;i++){
                Node *fr = q.front();
                q.pop();
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
        }

        return h;
    }
};

int main(){
    Tree t(1);
    t.insert(2);
    t.insert(3);
    t.insert(7);
    t.insert(6);
    t.insert(5);
    t.insert(4);

    t.display_reverse_recur();
    cout<<endl;
    t.display_reverse();

}