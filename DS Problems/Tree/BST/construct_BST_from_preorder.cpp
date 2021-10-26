#include <bits/stdc++.h>
using namespace std;

// Construct BST from given Preorder traversals

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}


Node* buildTree_utils(int pre[], int key, int *pI, int min, int max, int size)
{ // O(n) approach

    if(*pI>size) return NULL;

    Node* temp = NULL;

    if(key>min and key<max){
        temp = newNode(key);
        (*pI)++;
        if(*pI<size){
            temp->left = buildTree_utils(pre, pre[*pI], pI, min, key, size); 
            // Build left sub tree with values less than current key
        }
        if(*pI<size){
            temp->right = buildTree_utils(pre, pre[*pI], pI, key, max, size); 
            // Build right sub tree with values greater than current key
        }
    }
    
    return temp;
}


Node* buildTree_Efficient(int pre[], int len){ // O(n) approach
    
    int pI = 0; // Index in postorder

    return buildTree_utils(pre, pre[0], &pI, INT_MIN, INT_MAX, len);
}


void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int len = sizeof(pre) / sizeof(pre[0]);

    Node *root = buildTree_Efficient(pre, len);
    inorder(root);
}