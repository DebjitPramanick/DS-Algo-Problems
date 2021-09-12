#include <bits/stdc++.h>
using namespace std;

// Given a sorted doubly linked list of positive 
// distinct elements, the task is to find pairs in a 
// doubly-linked list whose sum is equal to given 
// value x, without using any extra space? 

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

        void findPairs(int sum){
            if(!head || !head->next) return;

            Node *last = head, *first = head;

            while(last->next) last = last->next;
            // I have last and first pointer

            while(first!=last){
                if((first->val+last->val) == sum){
                    cout<<"Ans is: "<<first->val<<"+"<<last->val<<endl;
                    break;
                }
                else if(first->val+last->val > sum)
                    last = last->prev;
                else first = first->next;
            }

        }

};

int main(){
    LinkedList l;
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    l.findPairs(25);
}

