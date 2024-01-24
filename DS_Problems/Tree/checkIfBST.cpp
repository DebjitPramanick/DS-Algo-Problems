#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root, *head, *newnode, *temp;

class BST
{
public:
    Node *create(int v)
    {
        newnode = new Node();
        newnode->data = v;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    void insert(Node *&node, int v)
    {
        if (node == NULL)
        {
            node = create(v);
            return;
        }
        if (v < node->data)
            insert(node->left, v);
        else
            insert(node->right, v);
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
            cout << cur->data << " ";
            cur = cur->right;
        }
    }
};

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


bool isGreater(Node *root, int key){
    if(root == NULL) return true;
    if(root->data > key && isGreater(root->left, key) && isGreater(root->right, key)){
        return true;
    }
    else{
        return false;
    }
}

bool isLesser(Node *root, int key){
    if(root == NULL) return true;
    if(root->data <= key && isLesser(root->left, key) && isLesser(root->right, key)){
        return true;
    }
    else{
        return false;
    }
}

bool isBST(Node *root){
    if(root == NULL) return true;
    if(isGreater(root->right, root->data) && isLesser(root->left, root->data)
    && isBST(root->right) && isBST(root->left)){
        return true;
    }
    else{
        return false;
    }
}


bool isBSTNormal(Node *root){
    stack<Node*> s;
    Node *prev = NULL;
    while(!s.empty() || root != NULL){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();

        if(prev!=NULL && root->data <= prev->data) return false;
        prev = root;
        root = root->right;
    }

    return true;
}

int main(){
    BST t1;
    Tree t2;
    int n, del;
    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter node: ";
        cin >> val;
        t1.insert(root ,val);
    }

    cout<<endl;

    cout << "Enter no. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cout << "Enter node: ";
        cin >> val;
        t2.insertNode(val);
    }

    t1.inorder();
    cout<<endl;
    t2.levelOrder();
    cout<<endl;


    bool res1 = false;
    bool res2 = false;
    res1 = isBSTNormal(root);
    res2 = isBST(head);
    if(res1) cout<<"First tree is a BST.";
    else cout<<"First tree is not a BST.";
    cout<<endl;
    if(res2) cout<<"Second tree is a BST.";
    else cout<<"Second tree is not a BST.";
}