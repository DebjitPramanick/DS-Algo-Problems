#include <bits/stdc++.h>
using namespace std;

/*
Write a function that returns true if the given Binary 
Tree is SumTree else false. A SumTree is a Binary Tree
where the value of a node is equal to the sum of the nodes 
present in its left subtree and right subtree. An empty 
tree is SumTree and the sum of an empty tree can be 
considered as 0. A leaf node is also considered as SumTree.
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

    void inorder(Node *head){
        if(!head) return;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }

    int sum(Node *node){
        if (node == NULL)
            return 0;

        return sum(node->left) + node->data +
               sum(node->right);
    }


    int checkUtils(Node *node){

        if(!node || (!node->left && !node->right)) return 1;

        int left = sum(node->left);
        int right = sum(node->right);

        if(!left and !right) return 1;
        else if(node->data == left+right 
        && checkUtils(node->left) 
        && checkUtils(node->right)) return 1;
        return 0;
    }

    void checkIfSumTree(){
        if(!root) cout<<"Valid"<<endl;
        int res = checkUtils(root);
        if(res) cout<<"Valid"<<endl;
        else cout<<"Not valid"<<endl;

    }
};

int main(){
    Tree t(26);
    t.insert(10);
    t.insert(3);
    t.insert(6);
    t.insert(4);
    t.insert(2);
    t.insert(1);

    t.checkIfSumTree();
    t.inorder(t.root);
}