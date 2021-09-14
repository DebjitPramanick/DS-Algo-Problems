#include <bits/stdc++.h>
using namespace std;

// The task is to create a doubly linked list by inserting 
// nodes such that list remains in ascending order on printing 
// from left to right. Also, we need to maintain two pointers, 
// head (points to first node) and tail (points to last node).

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
    Node *tail;
    public:
        LinkedList(){
            head = tail = NULL;
        }

        void insertNode(int v){
            Node *newNode = new Node();
            newNode->val = v;
            newNode->next = newNode->prev = NULL;
            if(!head) head = tail = newNode;
            
            else if(head->val >= newNode->val){
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            else if(tail->val <= newNode->val){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            else{
                Node *temp = head->next;
                while(temp->next){
                    if(temp->val>newNode->val){
                        temp->prev->next = newNode;
                        newNode->prev = temp->prev;
                        temp->prev = newNode;
                        newNode->next = temp;
                    }
                    temp = temp->next;
                }
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

};

int main(){
    LinkedList l;
    l.insertNode(6);
    l.insertNode(4);
    l.insertNode(2);
    l.insertNode(9);
    l.insertNode(5);
    l.insertNode(10);

    l.display();
}