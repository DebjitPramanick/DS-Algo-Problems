#include <bits/stdc++.h>
using namespace std;


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

    void display_SPRIAL(){
        stack<Node *> s1;
        stack<Node *> s2;

        s1.push(root);

        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                Node *tp =s1.top();
                cout<<tp->data<<" ";
                s1.pop();
                if(tp->right) s2.push(tp->right);
                if(tp->left) s2.push(tp->left);
            }

            while(!s2.empty()){
                Node *tp =s2.top();
                cout<<tp->data<<" ";
                s2.pop();
                if(tp->left) s1.push(tp->left);
                if(tp->right) s1.push(tp->right);
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

    t.display_SPRIAL();

}