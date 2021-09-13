#include <bits/stdc++.h>
using namespace std;

// Given a doubly-linked list, rotate the linked list 
// counter-clockwise by N nodes. Here N is a given 
// positive integer and is smaller than the count of 
// nodes in linked list. 

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

        int getCount(){
            Node *temp = head;
            int n = 0;
            while(temp) {
                n++;
                temp = temp->next;
            }
            return n;
        }

        void rotate(int k){
            if(!head || !head->next) return;
            int n = getCount();
            if(n<k) return;

            Node *temp = head;
            Node *newHead;
            int i = 0;
            while(i<k-1){
                i++;
                temp = temp->next;
            }
            newHead = temp->next;
            newHead->prev = NULL;
            temp->next = NULL;
            temp = newHead;
            while(temp->next) temp=temp->next;
            temp->next = head;
            head->prev = temp;
            head = newHead;
        }

};

int main(){
    LinkedList l;
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    l.rotate(2);
    l.display();
}

