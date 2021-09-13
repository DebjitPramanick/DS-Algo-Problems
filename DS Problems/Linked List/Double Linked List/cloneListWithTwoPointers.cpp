#include <bits/stdc++.h>
using namespace std;

// You are given a Double Link List with one pointer 
// of each node pointing to the next node just like 
// in a single link list. The second pointer however 
// CAN point to any node in the list and not just the 
// previous node. Now write a program in O(n) time to 
// duplicate this list. That is, write a program which 
// will create a copy of this list.


/*

Main List: 1->3->5>9->2
Arbirtary Links: 1->5, 9->1, 2->3

*/


class Node {
	public:
		int val;
		Node *next;
        Node *arb;
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
                if(temp->arb){
                    cout<<temp->val<<"(Arb: "<<temp->arb->val<<") -->";
                }
                else{
                    cout<<temp->val<<" -->";
                }
                
                temp = temp->next;
            }
            cout<<endl<<"Node count: "<<i<<endl;
        }

        void clone(){
            Node *cur = head, *temp;
            while(cur){
                temp = cur->next;
                cur->next = new Node();
                cur->next->val = cur->val;
                cur->next->next = temp;
                cur = temp;
            }

            cur = head;

            while(cur){
                cur->next->arb = cur->arb ? cur->arb->next : cur->arb;
                cur = cur->next->next;
            }

            Node *original = head;
            Node *copy = head->next;
            temp = copy;
            while(original and copy){
                original->next = original->next->next;
                copy->next = copy->next ? copy->next->next : copy->next;
                original = original->next;
                copy = copy->next;
            }
            if(!head) {
                cout<<"List is empty."<<endl;
                return;
            }
            
            int i = 0;
            while(temp){
                i++;
                if(temp->arb){
                    cout<<temp->val<<"(Arb: "<<temp->arb->val<<") -->";
                }
                else{
                    cout<<temp->val<<" -->";
                }
                
                temp = temp->next;
            }
            cout<<endl<<"Node count: "<<i<<endl;
        }

        void createArbLinks(){
            head->arb = head->next->next;
            head->next->next->next->arb = head;
            head->next->next->next->next->arb = head->next;
            cout<<"Done"<<endl;
        }

};

int main(){
    LinkedList l;
    l.insertNode(1);
    l.insertNode(3);
    l.insertNode(5);
    l.insertNode(9);
    l.insertNode(2);

    l.createArbLinks();
    l.display();
    l.clone();
    
}

