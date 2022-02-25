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

void util(Node* node, string res){


}

void solve(Node* root){
    
    map<int, Node*> mp;
    queue<pair<Node*, int>> q;

    vector<Node*> ans;
    q.push({root, 1});
    mp[1] = root;

    while(!q.empty()){
        Node* f = q.front().first;
        int dis = q.front().second;
        q.pop();

        if(mp.find(dis)==mp.end()) mp[dis] = f;

        if(f->left){
            q.push({f->left, dis-1});
        }
        if(f->right){
            q.push({f->right, dis+1});
        }
    }

    for(auto it: mp) cout<<it.second->val<<" ";

}


int main(){
    Tree t(1);
    srand(time(NULL));
    for(int i=2;i<=7;i++) t.insert(i);
    t.display();
    solve(t.root);
}