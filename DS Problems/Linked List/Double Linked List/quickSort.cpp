#include <bits/stdc++.h>
using namespace std;

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

        void swap ( int* a, int* b ){ 
            int t = *a; 
            *a = *b; 
            *b = t; 
        }

        Node *partition(Node *l, Node *h){
            int x = h->val;

            Node *i = l->prev;
            for(Node *j=l;j!=h;j=j->next){
                if(j->val <= x){
                    i = !i ? l : i->next;
                    swap(&(i->val), &(j->val));
                }
            }
            i = !i ? l : i->next;
            swap(&(i->val), &(h->val));
            return i;

        }

        void quickSort(Node *low, Node *high){
            if(high and low!=high and low!=high->next) {
                Node *p = partition(low, high);
                quickSort(low, p->prev);
                quickSort(p->next, high);
            }
        }

        void sort(){
            if(!head || !head->next) return;

            Node *temp = head;
            while(temp->next) temp = temp->next;
            quickSort(head, temp);
        }

};

int main(){
    LinkedList l;
    l.insertNode(6);
    l.insertNode(2);
    l.insertNode(1);
    l.insertNode(3);
    l.insertNode(5);

    l.display();
    l.sort();
    l.display();
}

