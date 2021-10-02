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

    void inorder(Node *head){
        if(!head) return;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }

    void storeInorder(vector<int> &temp, Node *node){ // Stores inorder in an array starting and ending with 0
        if(!node) return;
        storeInorder(temp, node->left);
        temp.push_back(node->data);
        storeInorder(temp, node->right);
    }

    void replaceSumUtils(Node *node, int *i, vector<int> temp){ // Replace sum with predecessor and successor
        if(!node) return;
        replaceSumUtils(node->left, i, temp);
        node->data = temp[*i-1] + temp[*i+1];
        ++*i;
        replaceSumUtils(node->right, i, temp);
    }

    void replaceWithSum(){ // Main function
        vector<int> temp;
        temp.push_back(0);
        storeInorder(temp, root);
        temp.push_back(0);
        int i = 1;
        replaceSumUtils(root, &i, temp);
    }
};

int main(){
    Tree t(1);
    for(int i=2; i<8; i++){
        t.insert(i);
    }

    t.replaceWithSum();
    t.inorder(t.root);
}