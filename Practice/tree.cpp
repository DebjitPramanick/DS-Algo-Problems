#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val = v;
        left = right = NULL;
    }
};

class Tree{

    public:
    Node* root = NULL;
    Tree(int val){
        root = new Node(val);
    }

    void insert(int val){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            if(!t->left){
                t->left = new Node(val);
                break;
            }
            else if(t->left) q.push(t->left);
            if(!t->right){
                t->right = new Node(val);
                break;
            }
            else if(t->right) q.push(t->right);
        }
    }

    void display(){
        queue<Node*> q;
        q.push(root);
        cout<<endl;
        while(!q.empty()){
            Node* t = q.front();
            cout<<t->val<<" ";
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        cout<<endl;
    }

    int height(Node* node){
        if(!node) return 0;
        return 1+max(height(node->left), height(node->right));
    }
};

Node* util(Node* node, int k, map<int, int> &mp, int l, int &np){
    if(!node) return NULL;
    if(node->val == k){
        mp[l] = node->val;
        node->val = mp[np++];
        return node;
    }

    mp[np] = node->val;

    Node *left, *right;
    left = util(node->left, k, mp, l+1, np);
    if(!left) right = util(node->right, k, mp, l+1, np);
    if(left || right) {
        node->val = mp[np++];
        return left ? left : right;
    }

    return NULL;
}

void solve(Node* root, int k){
    map<int, int> mp;
    int np = 0;
    root = util(root, k, mp, 0, np);
}


int main(){
    Tree t(2);
    srand(time(NULL));
    for(int i=1;i<7;i++) t.insert(rand()%100);
    t.display();
    solve(t.root, 8);
}