#include <bits/stdc++.h>
using namespace std;

// Given a sorted doubly linked list of distinct 
// nodes(no two nodes have the same data) and a value 
// x. Count triplets in the list that sum up to a 
// given value x.

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

        void findTriplets(int sum){
            if(!head || !head->next || !head->next->next) return;

            Node *last = head, *temp=head;

            while(last->next) last = last->next;
            // I have last and first pointer

            while(temp and temp->next and temp->next!=last){
                int rest =  sum - temp->val;
                Node *first = temp->next;
                Node* tail = last;
                while(rest > 0 and first!=tail){
                    if((first->val+tail->val) == rest){
                        cout<<"Ans is: "<<first->val<<"+"<<tail->val<<"+"<<temp->val<<endl;
                        first = first->next;
                        tail = tail->prev;
                    }
                    else if(first->val+tail->val > rest)
                        tail = tail->prev;
                    else first = first->next;
                }
                temp = temp->next;
            }

        }

};

int main(){
    LinkedList l;
    l.insertNode(1);
    l.insertNode(2);
    l.insertNode(4);
    l.insertNode(5);
    l.insertNode(6);
    l.insertNode(8);
    l.insertNode(9);

    l.display();
    l.findTriplets(17);
}

