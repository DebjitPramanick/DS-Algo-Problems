#include <bits/stdc++.h>
using namespace std;

// Print root to leaf paths without using recursion

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

    void printTopToBottom(Node *node, map<Node*, Node*> parent){
        stack<Node *> stk;
        while(node){
            stk.push(node);
            node = parent[node];
        }

        while(!stk.empty()){
            node = stk.top();
            stk.pop();
            cout<<node->data<<" ";
        }
        cout<<endl;
    }

    void printRootToLeaf(){
        map<Node*, Node*> parent;
        stack<Node *> st;
        st.push(root);
        parent[root] = NULL;

        while(!st.empty()){
            Node *tp = st.top();
            st.pop();
            if(!tp->left and !tp->right){
                printTopToBottom(tp, parent);
            }
            if(tp->right){
                parent[tp->right] = tp;
                st.push(tp->right);
            }
            if(tp->left){
                parent[tp->left] = tp;
                st.push(tp->left);
            }
        }
    }
};

int main()
{
    Tree t(1);
    for (int i = 2; i < 8; i++)
    {
        t.insert(i);
    }

    t.inorder(t.root);
    cout << endl;
    t.printRootToLeaf();
}