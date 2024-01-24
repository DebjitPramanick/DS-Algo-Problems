#include <bits/stdc++.h>
using namespace std;

/*
Find minimum swaps required to convert a Binary tree into Binary
Search Tree
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

    void inorder(Node *head){
        if(!head) return;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }

    void countMinSwaps(){
        if(!root) return;
        vector<pair<int, int>> v;
        stack<Node *> s;
        Node* cur = root;
        int idx = 0;
        int ans = 0;
        while(true){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if(s.empty()) break;
            cur = s.top();
            v.push_back(make_pair(cur->data, idx++));
            s.pop();
            cur = cur->right;
        }
        
        sort(v.begin(), v.end());

        for(int i=0;i<v.size();i++){
            if(i==v[i].second) continue;
            else{
                swap(v[i].first, v[v[i].second].first);
                swap(v[i].second, v[v[i].second].second);
            }
            if(i!=v[i].second) i--;
            ans++;
        }

        cout<<endl<<"Min swaps required = "<<ans<<endl;
    }
};

int main(){
    Tree t(5);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.insert(11);

    t.inorder(t.root);
    t.countMinSwaps();
}