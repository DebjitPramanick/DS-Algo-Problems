#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root, *newNode, *temp1, *temp2;

class AVL
{
public:
    Node *create(int val)
    {
        newNode = new Node();
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    int height(Node *root)
    {
        if (root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        return max(lh, rh) + 1;
    }

    int getBalancedFact(Node *root)
    {
        if (root == NULL)
            return -1;
        int lh = height(root->left);
        int rh = height(root->left);
        return (lh-rh);
    }

    Node *rightRotate(Node *root){
        temp1 = root->left;
        temp2 = temp1->right;
        temp1->right = root;
        root->left = temp2;
        return temp1;
    }

    Node *lefttRotate(Node *root){
        temp1 = root->right;
        temp2 = temp1->left;
        temp1->left = root;
        temp2->right = temp2;
        return temp1;
    }

    Node *insertNode(Node *root, int val)
    {
        if (root == NULL)
        {
            root = create(val);
            return root;
        }
        if (val < root->data)
            root->left = insertNode(root->left, val);
        else if(val > root->data){
            root->right = insertNode(root->right, val);
        }
        else{
            return root;
        }

        int bf = getBalancedFact(root);

        if(bf>1 && val<root->left->data){
            // Left-Left Case
            return rightRotate(root);
        }

        if(bf<-1 && val>root->right->data){
            // Right-Right Case
            return lefttRotate(root);
        }

        if(bf>1 && val>root->left->data){
            // Left-Right Case
            root->left = lefttRotate(root->left);
            return rightRotate(root);
        }

        if(bf<-1 && val<root->right->data){
            // Right-Left Case
            root->right = rightRotate(root->right);
            return lefttRotate(root);
        }

        return root;
    }
    
    void inorder()
    {
        if (root == NULL)
            return;

        stack<Node *> s;
        Node *cur = root;

        while (true)
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty())
                break;
            cur = s.top();
            s.pop();
            int bf = getBalancedFact(cur);
            cout << cur->data <<" --> "<<bf<<endl;
            cur = cur->right;
        }
    }
};

int main()
{
    AVL t;
    int n, del;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter node: ";
        cin >> val;
        root = t.insertNode(root, val);
    }

    t.inorder();
    cout << endl;
}