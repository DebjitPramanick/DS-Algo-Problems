#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertNode(int v)
    {
        Node *newNode = new Node();
        newNode->val = v;
        newNode->next = NULL;
        if (!head)
        {
            head = newNode;
            cout << "Item inserted." << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            cout << "Item inserted." << endl;
        }
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        int i = 0;
        while (temp)
        {
            i++;
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl
             << "Node count: " << i << endl;
    }

    void swapNodes(int x, int y)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        
        if (x == y) return;

        Node *prevX = NULL, *currX = head;
        while (currX && currX->val != x){
            prevX = currX;
            currX = currX->next;
        }

        Node *prevY = NULL, *currY = head;
        while (currY && currY->val != y){
            prevY = currY;
            currY = currY->next;
        }

        if (currX == NULL || currY == NULL) return;

        if (prevX != NULL) prevX->next = currY;
        else head = currY;

        if (prevY != NULL) prevY->next = currX;
        else head = currX;

        Node *temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
};

int main()
{
    LinkedList l;
    for (int i = 0; i < 5; i++)
    {
        l.insertNode(5 * (i + 1));
    }

    l.display();

    l.swapNodes(5, 15);
    l.display();
}
