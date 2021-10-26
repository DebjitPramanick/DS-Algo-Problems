#include <bits/stdc++.h>
using namespace std;

// Construct BST from given Inorder and Preorder traversals

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

Node* buildTree(char in[], char pre[], int inS, int inE){ // O(n2) approach
    static int pI = 0;
    if(inS > inE) return NULL;

    Node *temp = newNode(pre[pI++]); // Create node with char at preorder index from preorder array

    if(inS==inE) return temp;

    int inIndex = search(in, inS, inE, temp->data); // Finding inorder index of character

    temp->left = buildTree(in, pre, inS, inIndex-1); // Build left sub tree
    temp->right = buildTree(in, pre, inIndex+1, inE); // Build right sub tree

    return temp;
}


Node* buildTree_utils(char in[], char pre[], int inS, int inE, unordered_map<char, int> &mp)
{ // O(n) approach
    static int pI = 0;
    if(inS > inE) return NULL;

    char cur = pre[pI++];
    Node *temp = newNode(cur); // Create node with char at preorder index from preorder array

    if(inS==inE) return temp;

    int inIndex = mp[cur]; // Finding inorder index of character

    temp->left = buildTree_utils(in, pre, inS, inIndex-1, mp); // Build left sub tree
    temp->right = buildTree_utils(in, pre, inIndex+1, inE, mp); // Build right sub tree

    return temp;
}


Node* buildTree_Efficient(char in[], char pre[], int len){ // O(n) approach
    unordered_map<char, int> mp;
    for(int i=0;i<len;i++){
        mp[in[i]] = i;
    }

    return buildTree_utils(in, pre, 0, len-1, mp);
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

    // Node *root = buildTree(in, pre, 0, len-1);
    Node *root = buildTree_Efficient(in, pre, len);
    inorder(root);
}