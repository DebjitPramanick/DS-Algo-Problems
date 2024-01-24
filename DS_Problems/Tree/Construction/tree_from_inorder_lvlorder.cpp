#include <bits/stdc++.h>
using namespace std;

// Construct Tree from given Inorder and Preorder traversals

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

int search(int arr[], int s, int e, int target){
    int i;
    for(i=s; i<=e; i++){
        if(arr[i]==target) return i;
    }
    return -1;
}

int* extractKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m - 1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}

Node* buildTree(int in[], int level[], int inS, int inE, int n){
    if(inS > inE) return NULL;

    Node *temp = newNode(level[0]); // Create node with integer at 0th index from levelorder array

    if(inS==inE) return temp;

    int inIndex = search(in, inS, inE, temp->data); // Finding inorder index of integer

    // Extract left subtree keys from level order traversal
    int* llevel = extractKeys(in, level, inIndex, n);
 
    // Extract right subtree keys from level order traversal
    int* rlevel = extractKeys(in + inIndex + 1, level, n - 1, n);

    temp->left = buildTree(in, llevel, inS, inIndex-1, inIndex-inS); // Build left sub tree
    temp->right = buildTree(in, rlevel, inIndex+1, inE, inE-inIndex); // Build right sub tree

    delete[] llevel,
    delete[] rlevel;

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
    int in[] =  {4, 8, 10, 12, 14, 20, 22};
    int lvl[] = {20, 8, 22, 4, 12, 10, 14};
    int len = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree(in, lvl, 0, len-1, len);
    inorder(root);
}