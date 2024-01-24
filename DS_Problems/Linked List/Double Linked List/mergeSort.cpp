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

        Node* split(Node *hd){
            Node *fast = hd;
            Node *slow = hd;

            while(fast->next and fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
            }

            Node *temp = slow->next;
            slow->next = NULL;

            return temp;
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

        Node *mergeSort(Node *h){
            if (!h || !h->next) return h;
            Node *second = split(h);
            h = mergeSort(h);
            second = mergeSort(second);
            return merge(h, second);
        }

        void sort(){
            if(!head || !head->next) return;

            head = mergeSort(head);
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

