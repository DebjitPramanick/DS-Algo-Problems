#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root, *head, *newnode, *temp;


class Tree{
public:
    Node *createNode(int v){
        newnode = new Node();
        newnode->data = v;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    void insertNode(int v)
    {
        if (head == NULL){
            head = createNode(v);
            return;
        }
        queue<Node *> q;
        q.push(head);
        while (!q.empty()){
            temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            else if (temp->left == NULL){
                temp->left = createNode(v);
                return;
            }
            if (temp->right != NULL)
                q.push(temp->right);
            else{
                temp->right = createNode(v);
                return;
            }
        }
    }

    void levelOrder(){
        if (head == NULL)
            return;
        queue<Node *> q;
        q.push(head);

        while (!q.empty()){
            Node *cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
        }
    }

};


bool isBalancedTimeLess(Node *root, int* height){ // Time complexity -> O(n)
    if(root == NULL){
        return true;
    }

    int lh = 0, rh = 0;

    if(isBalancedTimeLess(root->left, &lh) == false) return false;
    if(isBalancedTimeLess(root->right, &rh) == false) return false;

    *height = max(lh,rh) + 1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}


int height(Node *root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}


bool isBalanced(Node *root){ // Time Complexity is -> O(n^2)
    if(root == NULL){
        return true;
    }
    if(isBalanced(root->left) == false) return false;
    if(isBalanced(root->right) == false) return false;

    int lh = height(root->left);
    int rh = height(root->left);

    if(abs(lh-rh) <= 1) return true;
    else return false;
}


int main(){
    Tree t;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter node: ";
        cin >> val;
        t.insertNode(val);
    }

    cout<<endl;
    t.levelOrder();
    cout<<endl;

    if(isBalanced(root)) cout<<"Tree is balaned."<<endl;
    else cout<<"Tree is not balanced"<<endl;

    if(isBalancedTimeLess(root, 0)) cout<<"Tree is balaned."<<endl;
    else cout<<"Tree is not balanced"<<endl;
}