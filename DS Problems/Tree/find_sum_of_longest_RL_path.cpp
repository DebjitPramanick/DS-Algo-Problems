#include <bits/stdc++.h>
using namespace std;

/*
Sum of Nodes on the longest path from root to leaf node
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

    void sumUtils(Node *node, int sum, int len, int &maxSum, int &maxLen){
        if(!node) {
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen && maxSum<sum) maxSum = sum;
            return;
        }
        sumUtils(node->left, sum+node->data, len+1, maxSum, maxLen);
        sumUtils(node->right, sum+node->data, len+1, maxSum, maxLen);
    }

    void findSum(){
        if(!root) return;
        int sum = INT_MIN, len = 0;
        sumUtils(root, 0, 0, sum, len);
        cout<<endl<<sum<<endl;
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
    t.insert(4);

    t.inorder(t.root);
    t.findSum();
}