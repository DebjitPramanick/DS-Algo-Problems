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

    void display_Dir_Change(){
        stack<Node *> s;
        queue<Node *> q;
        bool rl = false;
        int ct = 0;

        q.push(root);

        while(!q.empty()){
            ct++;
            int sz = q.size();

            for(int i=0;i<sz;i++){
                Node *fr = q.front();
                q.pop();
                
                if(!rl) cout<<fr->data<<" ";
                else s.push(fr);
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }

            if(rl){
                while(!s.empty()){
                    Node *tp = s.top();
                    s.pop();
                    cout<<tp->data<<" ";
                }
            }

            if(ct==2) {
                rl = !rl;
                ct = 0;
            }
            
            

        }
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
    t.insert(9);
    t.insert(8);
    t.insert(11);
    t.insert(12);
    t.insert(15);
    t.insert(14);
    t.insert(16);
    t.insert(20);
    t.insert(30);
    t.insert(36);
    t.insert(50);

    t.display_Dir_Change();

}