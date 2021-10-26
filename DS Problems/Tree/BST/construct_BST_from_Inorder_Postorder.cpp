#include <bits/stdc++.h>
using namespace std;

// Construct BST from given Inorder and Postorder traversals

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


Node* buildTree_utils(int in[], int post[], int inS, int inE, int *pI, unordered_map<int, int> &mp)
{ // O(n) approach
    if(inS > inE) return NULL;

    int cur = post[*pI];
    Node *temp = newNode(cur); // Create node with int at postorder index from postorder array
    (*pI)--;

    if(inS==inE) return temp;

    int inIndex = mp[cur]; // Finding inorder index of integer

    temp->right = buildTree_utils(in, post, inIndex+1, inE, pI, mp); // Build right sub tree
    temp->left = buildTree_utils(in, post, inS, inIndex-1, pI, mp); // Build left sub tree
    
    return temp;
}


Node* buildTree_Efficient(int in[], int post[], int len){ // O(n) approach
    unordered_map<int, int> mp;
    for(int i=0;i<len;i++){
        mp[in[i]] = i;
    }
    int index = len - 1; // Index in postorder

    return buildTree_utils(in, post, 0, len-1, &index, mp);
}


void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int in[] = { 3, 5, 6, 7, 8, 9, 10 };
    int post[] = { 3, 6, 5, 8, 10, 9, 7 };
    int len = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree_Efficient(in, post, len);
    inorder(root);
}