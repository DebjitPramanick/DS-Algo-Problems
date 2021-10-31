#include <bits/stdc++.h>
using namespace std;

/*

*/

struct Node
{
    string data;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Node *root = new Node();

    Tree(string val)
    {
        root->data = val;
        root->right = root->left = NULL;
    }

    void insert(string val)
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

    int toInt(string s)
    {
        int num = 0;

        // Check if the integral value is
        // negative or not
        // If it is not negative, generate the number
        // normally
        if (s[0] != '-')
            for (int i = 0; i < s.length(); i++)
                num = num * 10 + (int(s[i]) - 48);
        // If it is negative, calculate the +ve number
        // first ignoring the sign and invert the
        // sign at the end
        else
            for (int i = 1; i < s.length(); i++)
            {
                num = num * 10 + (int(s[i]) - 48);
                num = num * -1;
            }

        return num;
    }

    int evalUtil(Node *node)
    {
        if (!node)
            return 0;
        if (!node->left and !node->right) return toInt(node->data);
        int lVal = evalUtil(node->left);
        int rVal = evalUtil(node->right);
        if(node->data == "+") return lVal+rVal;
        else if(node->data == "-") return lVal-rVal;
        else if(node->data == "/") return lVal/rVal;
        return lVal*rVal;
    }

    void eval()
    {
        if (!root)
            return;
        int ans = evalUtil(root);
        cout<<endl<<ans<<endl;
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

int main()
{
    Tree t("+");
    t.insert("-");
    t.insert("/");
    t.insert("20");
    t.insert("12");
    t.insert("16");
    t.insert("4");

    t.inorder(t.root);
    cout<<endl;
    t.eval();
}