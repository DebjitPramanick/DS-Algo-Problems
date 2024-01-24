#include <bits/stdc++.h>
using namespace std;

/*
Convert BST into Balanced BST.
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

    Node* newNode(int data){
        Node* node = new Node();
        node->data = data;
        node->left = node->right = NULL;
        return (node);
    }

    void customTree(){
        root->left = newNode(20);
        root->left->left = newNode(10);
    }

    void inorder(Node *node){
        if(!node) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    vector<Node *> storeInorder(){
        stack<Node*> s;
        Node *temp = root;
        vector<Node*> v;

        while(true){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            if(s.empty()) break;
            temp = s.top();
            s.pop();
            v.push_back(temp);
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

    Node* buildTree(vector<Node*> &nodes, int s, int e){
        if(s>e) return NULL;

        int m = (s+e)/2; 
        Node* curNode = nodes[m];

        curNode->left = buildTree(nodes, s, m-1);
        curNode->right = buildTree(nodes, m+1, e);

        return curNode;

    }

    void convertToBalancedBST(){
        vector<Node*> nodes = storeInorder();
        int n = nodes.size();
        root = buildTree(nodes, 0, n-1);
    }
    
};

int main(){
    Tree t(30);
    t.customTree();

    t.convertToBalancedBST();
    cout<<t.root->data<<endl;
    cout<<t.root->left->data<<endl;
    cout<<t.root->right->data<<endl;
    t.inorder(t.root);
}