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

    Node *root = new Node();

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

    void inorder(Node *node){
        if(!node) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
};

bool check(Node *head1, Node *head2){
    if(!head1 and !head2) return true;
    if(!head1 || !head2) return false;

    return (head1->data == head2->data and check(head1->right, head2->left)
    and check(head1->left, head2->right));
}

int main(){
    Tree t1(1);
    Tree t2(1);

    t1.insert(2);
    t1.insert(3);
    t1.insert(4);
    t1.insert(5);
    t1.insert(6);
    t1.insert(7);

    t2.insert(3);
    t2.insert(2);
    t2.insert(7);
    t2.insert(6);
    t2.insert(5);
    t2.insert(4);

    t1.inorder(t1.root);
    cout<<endl;
    t2.inorder(t2.root);
    cout<<endl<<check(t1.root, t2.root);
}