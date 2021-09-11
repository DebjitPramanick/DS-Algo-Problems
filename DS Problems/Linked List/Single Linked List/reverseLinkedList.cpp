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

        void reverseList(){ // Without recursion
            if(!head || !head->next) return;
            Node *temp = head;
            Node *q, *p, *t;
            q = NULL;

            while(temp){
                p = temp;
                temp = temp->next;
                p->next = NULL;
                p->next = q;
                q = p;
                p = NULL;
            }
            head = q;
        }

        Node *util(Node *h){
            if(!h || !h->next) return h;
            Node *rest = util(h->next);
            h->next->next = h;
            h->next = NULL;
            return rest;
        }

        void recursiveReversal(){
            if(!head) return;
            head = util(head);
        }

};

int main(){
    LinkedList l;

    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    l.reverseList();
    l.display();
    l.recursiveReversal();
    l.display();
}

