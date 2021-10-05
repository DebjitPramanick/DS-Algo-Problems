#include <bits/stdc++.h>
using namespace std;

/*
Given a Binary Tree, check if all leaves are at same level or not. 
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

    void check(){

        queue<Node*> q;
        q.push(root);
        vector<pair<int, int>> leaves;
        int c = 0;
        int flag = 0;
        while(!q.empty()){
            int s = q.size();
            c++;

            for(int i=0;i<s;i++){
                Node *fr = q.front();
                q.pop();
                if(!fr->left and !fr->right) leaves.push_back(make_pair(fr->data, c));
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
        }

        for(int i=0;i<leaves.size()-1;i++){
            if(leaves[i].second != leaves[i+1].second) {
                cout<<"Leaves are not at same level";
                flag = 1;
                break;
            }
        }
        if(!flag) cout<<"Leaves are at same level";
    }


};

int main(){
    Tree t(1);
    for(int i=2;i<=6;i++) t.insert(i);
    t.check();
}