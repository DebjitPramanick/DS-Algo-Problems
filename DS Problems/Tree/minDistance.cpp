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


Node *LCA(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->left, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }

    if(left== NULL && right == NULL){
        return NULL;
    }

    if(left!=NULL){
        return LCA(root->left, n1,n2);
    }
    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist){
    if(root == NULL) return -1;
    if(root->data == k) return dist;

    int left = findDist(root->left, k, dist+1);
    if(left!=-1) return left;
    return findDist(root->right, k, dist+1);
}


int distBtwNodes(Node *root, int n1, int n2){
    Node *lca = LCA(root, n1, n2);
    cout<<lca->data<<endl;
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1+d2;
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

    int dist = distBtwNodes(root, 3,9);
    cout<<dist<<endl;
}