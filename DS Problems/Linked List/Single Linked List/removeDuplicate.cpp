#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int val;
		Node *next;
		Node(){
			next = NULL;
		}
};


class LinkedList {
    Node *head;


    void split(Node *t, Node **a, Node **b){
        Node *fast, *slow;
        fast = t->next;
        slow = t;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        *a = t;
        *b = slow->next;
        slow->next = NULL;
    }

    Node* sortedMerge(Node *a, Node *b){
        Node *res = NULL;
        if(!a) return (b);
        else if(!b) return (a);
        if(a->val <= b->val){
            res = a;
            res->next = sortedMerge(a->next, b);
        }
        else{
            res = b;
            res->next = sortedMerge(a, b->next);
        }

        return (res);
    }

    void mergeSort(Node **head){
        Node* temp = *head;
        Node *a, *b;
        if(!temp || !temp->next) return;
        split(temp, &a, &b);
        mergeSort(&a);
        mergeSort(&b);
        *head = sortedMerge(a ,b);
    }


    public:
        LinkedList(){
            head = NULL;
        }
        
        void insertNode(int v){
            Node *newNode = new Node();
            newNode->val = v;
            newNode->next = NULL;
            if(!head){
                head = newNode;
                cout<<"Item inserted."<<endl;
            }
            else{
                Node *temp = head;
                while(temp->next)
                    temp = temp->next;
                temp->next = newNode;
                cout<<"Item inserted."<<endl;
            }
        }
        void display(){
            if(!head) {
                cout<<"List is empty."<<endl;
                return;
            }
            Node *temp = head;
            int i = 0;
            while(temp){
                i++;
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<endl<<"Node count: "<<i<<endl;
        }

        void sort(){
            if(!head){
                cout<<"List is empty."<<endl;
                return;
            }
            mergeSort(&head);
        }

        void reomveDuplicates(){
            if(!head || !head->next) return;
            Node *temp = head;
            while(temp and temp->next){
                int cur = temp->val;
                if(temp->next->val == cur){
                    Node* fr = temp->next;
                    temp->next = fr->next;
                    free(fr);
                }
                else temp = temp->next;
            }
        }

};

int main(){
    LinkedList l;

    l.insertNode(11);
    l.insertNode(34);
    l.insertNode(22);
    l.insertNode(11);
    l.insertNode(20);
    l.insertNode(32);
    l.insertNode(20);
    l.insertNode(11);
    l.insertNode(11);

    l.display();
    l.sort();
    l.display();
    l.reomveDuplicates();
    l.display();
}

