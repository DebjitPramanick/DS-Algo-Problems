#include <bits/stdc++.h>
using namespace std;

/*
Convert binary tree into BST.
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

    void inorder(Node *node){
        if(!node) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    vector<int> storeInorder(){
        stack<Node*> s;
        Node *temp = root;
        vector<int> v;

        while(true){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            if(s.empty()) break;
            temp = s.top();
            s.pop();
            v.push_back(temp->data);
            temp = temp->right;
        }

        return v;
    }

    void insert(vector<int> nodes, Node* node, int *i){
        if (node == NULL)
        return;
 
        insert(nodes, node->left, i);
    
        /* Now update root's data and increment index */
        node->data = nodes[*i];
        (*i)++;
    
        /* finally update the right subtree */
        insert(nodes, node->right, i);
    }

    void convertToBST(){
        vector<int> nodes = storeInorder();
        sort(nodes.begin() ,nodes.end());
        int i = 0;
        insert(nodes, root, &i);
    }
    
};

int main(){
    Tree t(1);
    t.insert(2);
    t.insert(3);
    t.insert(7);
    t.insert(6);
    t.insert(5);
    t.insert(4);

    t.convertToBST();
    t.inorder(t.root);



}