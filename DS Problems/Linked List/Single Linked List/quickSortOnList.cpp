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

        Node *getTail(Node *h){
            while(h && h->next) h = h->next;
            return h;
        }

        Node *partition(Node *h, Node *end, Node **nh, Node **ne){
            Node *pivot = end;
            Node *prev = NULL, *cur = h, *tail = end;

            while(cur != pivot){
                if(cur->val < pivot->val){
                    if(!(*nh)) (*nh) = cur;
                    prev = cur;
                    cur = cur->next;
                }
                else{
                    if(prev){
                        prev->next = cur->next;
                    }
                    Node *tmp = cur->next;
                    cur->next = NULL;
                    tail->next = cur;
                    tail = cur;
                    cur = tmp;
                }
            }   

            if(!(*nh)) (*nh) = pivot;
            (*ne) = tail;
            return pivot;
        }


        Node *quickSortRecur(Node *h, Node *end){
            if(!h || h==end) return h;
            Node *newHead = NULL, *newEnd = NULL;

            Node *pivot = partition(h, end, &newHead, &newEnd);

            if(newHead != pivot){
                struct Node* tmp = newHead;
                while (tmp->next != pivot) tmp = tmp->next;
                tmp->next = NULL;
                newHead = quickSortRecur(newHead, tmp);
                tmp = getTail(newHead);
                tmp->next = pivot;
            }

            pivot->next = quickSortRecur(pivot->next, newEnd);
            return newHead;
        }

        

        void sort(){
            if(!head) return;
            Node **headRef = &head;
            (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
        }

};

int main(){
    LinkedList l;
    l.insertNode(5);
    l.insertNode(10);
    l.insertNode(4);
    l.insertNode(9);
    l.insertNode(2);

    l.display();
    l.sort();
    l.display();
}

