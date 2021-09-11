#include <bits/stdc++.h>
using namespace std;

// Given two lists sorted in increasing order, create 
// and return a new list representing the intersection 
// of the two lists. The new list should be made with 
// its own memory — the original lists should not 
// be changed. 

class Node {
	public:
		int val;
		Node *next;
		Node(){
			next = NULL;
		}
};


class LinkedList {
    
    public:

        Node *head;

        LinkedList(){
            head = NULL;
        }
        
        void insertNode(int v){
            Node *newNode = new Node();
            newNode->val = v;
            newNode->next = NULL;
            if(!head){
                head = newNode;
            }
            else{
                Node *temp = head;
                while(temp->next)
                    temp = temp->next;
                temp->next = newNode;
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

        void findIntersection(Node *b){
            Node *dumHead = NULL;
            Node *tail;

            Node *a = head;

            while(a and b){
                if(a->val == b->val){
                    Node *nd = new Node();
                    nd->val = a->val;
                    nd->next = NULL;
                    if(!dumHead) dumHead = tail = nd;
                    else {
                        tail->next = nd;
                        tail = nd;
                    }

                    a = a->next;
                    b = b->next;

                }
                else if(a->val < b->val) a = a->next;
                else b = b->next;
            }

            tail = dumHead;

            while(tail){
                cout<<tail->val<<" ";
                tail = tail->next;
            }


        }
        
};

int main(){
    LinkedList l1, l2;

    for(int i=0;i<10;i++){
        l1.insertNode(2*(i+1));
        l2.insertNode(4*(i+1));
    }

    l1.display();
    l2.display();

    l1.findIntersection(l2.head);

}

