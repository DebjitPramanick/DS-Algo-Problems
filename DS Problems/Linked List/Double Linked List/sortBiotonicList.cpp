#include <bits/stdc++.h>
using namespace std;


// Sort the given biotonic doubly linked list. A biotonic 
// doubly linked list is a doubly linked list which is first 
// increasing and then decreasing. A strictly increasing or a 
// strictly decreasing list is also a biotonic doubly linked list.

/*
2 --> 5 --> 7 --> 12 --> 10 --> 6 --> 4 --> 1
*/


class Node {
	public:
		int val;
		Node *next;
        Node *prev;
		Node(){
			next = NULL;
		}
};


class LinkedList {
    Node *head;
    public:
        LinkedList(){
            head = NULL;
        }

        void insertNode(int v){
            Node *newNode = new Node();
            newNode->val = v;
            newNode->next = newNode->prev = NULL;
            if(!head){
                head = newNode;
                cout<<"Item inserted."<<endl;
            }
            else{
                Node *temp = head;
                while(temp->next)
                    temp = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
            }
        }

        Node *merge(Node *l, Node *h){
            if(!l) return h;
            if(!h) return l;
            if(l->val < h->val){
                l->next = merge(l->next, h);
                l->next->prev = l;
                l->prev = NULL;
                return l;
            }
            h->next = merge(l, h->next);
            h->next->prev = h;
            h->prev = NULL;
            return h;
        }

        Node* reverse(Node *s){
            if(!s) return NULL;
            Node *temp = s, *p = NULL;

            while(temp){
                p = temp->prev;
                temp->prev = temp->next;
                temp->next = p;
                temp = temp->prev;
            }

            return p->prev;

        }

        void sort(){
            if(!head || !head->next) return;

            Node *temp =head;
            while(temp and temp->next){
                if(temp->val > temp->next->val) break;
                temp = temp->next;
            }

            if(!temp->next) return;

            // Split the list

            Node *first = head;
            Node *second = temp->next;
            second->prev = NULL;
            temp->next = NULL;
            second = reverse(second);

            cout<<first->val<<" "<<second->val<<endl;

            // Merge the list

            head = merge(first, second);
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

};

int main(){
    LinkedList l;
    l.insertNode(2);
    l.insertNode(5);
    l.insertNode(7);
    l.insertNode(12);
    l.insertNode(10);
    l.insertNode(6);
    l.insertNode(4);
    l.insertNode(1);

    l.display();
    l.sort();
    l.display();
}