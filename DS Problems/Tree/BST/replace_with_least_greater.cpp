#include <bits/stdc++.h>
using namespace std;

/*
Replace every element with the least greater element on its right
*/


struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int item){
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}

Node *insert(Node *node, int data, Node*& succ){
    if(!node) return node = newNode(data);
    if(data<node->data){
        succ = node;
        node->left = insert(node->left, data, succ);
    }
    else node->right = insert(node->right, data, succ);
    return node;
}

void replace(int arr[], int n){
    Node *root = NULL;
    for(int i=n-1;i>=0;i--){
        Node *succ = NULL;
        root = insert(root, arr[i], succ);
        if(succ) arr[i] = succ->data;
        else arr[i] = -1;
    }
}


int main(){
    int arr[] = { 8,  58, 71, 18, 31, 32, 63, 92,
                  43, 3,  91, 93, 25, 80, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);
    replace(arr, n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}