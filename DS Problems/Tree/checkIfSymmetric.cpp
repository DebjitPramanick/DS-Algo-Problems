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

bool check_iterative(Node *head1, Node *head2){
    stack<Node*> s1, s2;

    s1.push(head1);
    s2.push(head2);

    while(true){
        while(head1 and head2){
            if(head1->data != head2->data) return false;
            s1.push(head1);
            s2.push(head2);
            head1 = head1->left;
            head2 = head2->right;
        }

        if(!(!head1 && !head2)) return false;
        if(!s1.empty() and !s2.empty()){
            head1 = s1.top();
            head2 = s2.top();

            s1.pop();
            s2.pop();

            head1 = head1->right;
            head2 = head2->left;
        }
        else break;
    }

    return true;
}

void checkMain(Node *head){

    if(!head) cout<<"Symmetric.";
    else if(!head->left || !head->right) cout<<"Not Symmetric";
    else{
        bool res = check_iterative(head->left, head->right);
        if(res) cout<<"Symmetric.";
        else cout<<"Not Symmetric";
    }
}

void checkSingleFunc(Node *head){
    if(!head) cout<<"Symmetric.";
    else if(!head->left && !head->right) cout<<"Symmetric";
    else{
        queue<Node *> q;
        q.push(head);
        q.push(head);

        Node *lnode, *rnode;

        while(!q.empty()){
            lnode = q.front();
            q.pop();
            rnode = q.front();
            q.pop();

            if(lnode->data != rnode->data){
                cout<<"Not Symmetric";
                return;
            }

            if(lnode->left and rnode->right){
                q.push(lnode->left);
                q.push(rnode->right);
            }

            else if(lnode->left || rnode->right){
                cout<<"Not Symmetric";
                return;
            }

            if(lnode->right and rnode->left){
                q.push(lnode->right);
                q.push(rnode->left);
            }

            else if(lnode->right || rnode->left){
                cout<<"Not Symmetric";
                return;
            }
        }
    }

    cout<<"Symmetric";

}

int main(){
    Tree t1(1);

    t1.insert(2);
    t1.insert(2);
    t1.insert(3);
    t1.insert(4);
    t1.insert(4);
    t1.insert(3);

    t1.inorder(t1.root);
    checkMain(t1.root);
    checkSingleFunc(t1.root);
}