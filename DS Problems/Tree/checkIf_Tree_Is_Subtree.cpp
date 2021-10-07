#include <bits/stdc++.h>
using namespace std;

/*
Leaf traversal is sequence of leaves traversed from left to right. 
The problem is to check if leaf traversals of two given Binary 
Trees are same or not.
Expected time complexity O(n). Expected auxiliary space O(h1 + h2) 
where h1 and h2 are heights of two Binary Trees.
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Node *root = new Node();

    Tree(int val)
    {
        root->data = val;
        root->right = root->left = NULL;
    }

    void insert(int val)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *tp = q.front();
            q.pop();
            if (tp->left)
            {
                q.push(tp->left);
            }
            else
            {
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->left = newNode;
                break;
            }
            if (tp->right)
            {
                q.push(tp->right);
            }
            else
            {
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->right = newNode;
                break;
            }
        }
    }

    void inorder(Node *head)
    {
        if (!head)
            return;
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
};


void storeInorder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] = root->data;
    storeInorder(root->right, arr, i);
}
void storePreOrder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->data;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}
 
bool isSubtree(Node* T, Node* S)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
 
    int m = 0, n = 0;
    char inT[50], inS[50];
    storeInorder(T, inT, m);
    storeInorder(S, inS, n);
    inT[m] = '\0', inS[n] = '\0';
 
    if (strstr(inT, inS) == NULL)
        return false;
 
    m = 0, n = 0;
    char preT[50], preS[50];
    storePreOrder(T, preT, m);
    storePreOrder(S, preS, n);
    preT[m] = '\0', preS[n] = '\0';

    return (strstr(preT, preS) != NULL);
}

int main()
{
    Tree t1(1);
    Tree t2(2);

    t1.insert(2);
    t1.insert(3);
    t1.insert(4);
    t1.insert(5);
    t1.insert(6);
    t1.insert(7);

    t2.insert(8);
    t2.insert(5);

    t1.inorder(t1.root);
    cout << endl;
    t2.inorder(t2.root);
    cout << endl;
    cout<<isSubtree(t1.root, t2.root);
}