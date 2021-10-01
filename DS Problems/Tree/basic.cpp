#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;
};

class Tree{
    public:

    Node *root;

    Tree(int val){
        root->data = val;
        root->right = root->left = NULL;
    }

    void insert(int val){
        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            Node *tp = q.front();
            q.pop();
            if(tp->left){
                q.push(tp->left);
            }
            else{
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->left = newNode;
                break;
            }
            if(tp->right){
                q.push(tp->right);
            }
            else{
                Node *newNode = new Node();
                newNode->data = val;
                newNode->right = NULL;
                newNode->left = NULL;
                tp->right = newNode;
                break;
            }
        }
    }

    void display_BFS(){
        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            Node *tp = q.front();
            q.pop();
            cout<<tp->data<<" ";
            if(tp->left) q.push(tp->left);
            if(tp->right) q.push(tp->right);
        }

        cout<<endl;
    }

    void inorder(Node *head){
        if(!head) return;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }

    void preorder(Node *head){
        if(!head) return;
        cout<<head->data<<" ";
        inorder(head->left);
        inorder(head->right);
    }

    void postorder(Node *head){
        if(!head) return;
        inorder(head->left);
        inorder(head->right);
        cout<<head->data<<" ";
    }

    void deleteUtils(Node *tg){
        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            Node *tp = q.front();
            q.pop();
            if(tp == tg){
                tp = NULL;
                delete(tg);
                break;
            }
            
            if(tp->right){
                if(tp->right == tg){
                    tp->right = NULL;
                    delete(tg);
                    break;
                }
                else q.push(tp->right);
            }

            if(tp->left){
                if(tp->left == tg){
                    tp->left = NULL;
                    delete(tg);
                    break;
                }
                else q.push(tp->left);
            }
            
        }
    }

    void deleteNode(int val){
        queue<Node *> q;
        Node *kN = NULL;
        Node *tp;
        q.push(root);

        while(!q.empty()){
            tp = q.front();
            q.pop();
            if(tp->data == val){
                kN = tp;
            }

            if(tp->left){
                q.push(tp->left);
            }
            if(tp->right){
                q.push(tp->right);
            }
        }

        if(kN){
            int x = tp->data;
            deleteUtils(kN);
            kN->data = x;
        }
    }
};

int main(){
    Tree t(3);
    for(int i=0; i<10; i++){
        t.insert((i+1)*3);
    }

    t.display_DFS();
    t.inorder(t.root);
    cout<<endl;
    t.preorder(t.root);
    cout<<endl;
    t.postorder(t.root);
    cout<<endl;
    t.deleteNode(18);
    t.display_DFS();
}