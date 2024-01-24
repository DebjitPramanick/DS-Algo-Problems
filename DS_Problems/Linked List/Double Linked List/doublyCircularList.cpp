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
            if(!head){
                head = newNode;
                head->next = head;
                head->prev = head;
                cout<<"Item inserted."<<endl;
            }
            else{
                Node *temp = head;
                while(temp->next != head)
                    temp = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = head;
                head->prev = newNode;
            }
        }

        void deleteNode(int v){
            if(!head){
                cout<<"List is empty."<<endl;
                return;
            }
            Node *temp = head;
            if(temp->val== v){
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                head = temp->next;

                temp->next = NULL;
                temp->prev = NULL;
                free(temp);
                cout<<"List item deleted."<<endl;
                return;
            }
            temp = temp->next;
            while(temp!=head){
                if(temp->val == v){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = NULL;
                    free(temp);
                    cout<<"List item deleted."<<endl;
                    return;
                }
                temp = temp->next;
            }
        }

        int searchNode(int v){
            if(!head) return -1;
            Node *temp = head;
            int i = 0;
            while(temp->next != head){
                i++;
                if(temp->val== v) break;
                temp = temp->next;
            }
            if(temp->next == head and temp->val== v) i++;;
            return i;
        }

        void display(){
            if(!head) {
                cout<<"List is empty."<<endl;
                return;
            }
            Node *temp = head;
            int i = 0;
            while(temp->next != head){
                i++;
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            i++;
            cout<<temp->val<<" ";
            temp = temp->next;
            cout<<endl<<"Node count: "<<i<<endl;
        }

};

int main(){
    LinkedList l;
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    cout<<l.searchNode(25)<<endl;
    l.deleteNode(5);
    l.display();
    l.deleteNode(25);
    l.display();
}