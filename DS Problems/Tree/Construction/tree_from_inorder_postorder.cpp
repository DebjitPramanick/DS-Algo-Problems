#include <bits/stdc++.h>
using namespace std;

// Construct Tree from given Inorder and Preorder traversals

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node* newNode(char data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

int search(char ch[], int s, int e, char target){
    int i;
    for(i=s; i<=e; i++){
        if(ch[i]==target) return i;
    }
    return -1;
}

Node* buildTree(char in[], char pre[], int inS, int inE){
    static int pI = 0;
    if(inS > inE) return NULL;

    Node *temp = newNode(pre[pI++]); // Create node with char at preorder index from preorder array

    if(inS==inE) return temp;

    int inIndex = search(in, inS, inE, temp->data); // Finding inorder index of character

    temp->left = buildTree(in, pre, inS, inIndex-1); // Build left sub tree
    temp->right = buildTree(in, pre, inIndex+1, inE); // Build right sub tree

    return temp;
}

void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree(in, pre, 0, len-1);
    inorder(root);
}