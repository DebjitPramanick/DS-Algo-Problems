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

Node* utils(int in[], int post[], int s, int e, int *index, map<int, int> &mp){
    if(s>e) return NULL;
    int cur = post[*index];
    Node* node = new Node(cur);
    (*index)--;

    if(s == e) return node;

    int inIndex = mp[cur];
    Node* l = utils(in, post, s, inIndex-1, index, mp);
    Node* r = utils(in, post, inIndex+1, e, index, mp);

    return node;
}

Node* solve(int in[], int post[], int n){
    map<int, int> mp;
    for(int i=0;i<n;i++) mp[in[i]] = i;
    int index = n-1;
    return utils(in, post, 0, n-1, &index, mp);
}


int main(){
    int in[] = { 3, 5, 6, 7, 8, 9, 10 };
    int post[] = { 3, 6, 5, 8, 10, 9, 7 };
    int len = sizeof(in) / sizeof(in[0]);

    Node *root = solve(in, post, len);
    
}