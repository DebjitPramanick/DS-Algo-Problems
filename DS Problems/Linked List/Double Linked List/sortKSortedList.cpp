#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
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
        newNode->next = newNode->prev = NULL;
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
            newNode->prev = temp;
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

    void sortList(int k) // Applying insertion sort O(n*k)
    {
        if (!head || !head->next)
            return;

        for (Node *i = head->next; i != NULL; i = i->next){

            Node *j = i;

            while (j->prev && j->val < j->prev->val){

                Node *temp = j->prev->prev;
                Node *temp2 = j->prev;
                Node *temp3 = j->next;
                j->prev->next = temp3;
                j->prev->prev = j;
                j->prev = temp;
                j->next = temp2;
                if (temp) temp->next = j;
                if (temp3) temp3->prev = temp2;
            }

            if (!j->prev)
                head = j;
        }
    }
};

int main()
{
    LinkedList l;
    l.insertNode(6);
    l.insertNode(4);
    l.insertNode(1);
    l.insertNode(8);
    l.insertNode(2);

    l.display();
    l.sortList(2);
    l.display();
}
