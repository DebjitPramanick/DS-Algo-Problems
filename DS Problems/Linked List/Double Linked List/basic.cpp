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

        void deleteNode(int v){
            if(!head){
                cout<<"List is empty."<<endl;
                return;
            }
            Node *temp = head;
            if(temp->val== v){
                head = temp->next;
                temp->next = NULL;
                head->prev = NULL;
                free(temp);
                cout<<"List item deleted."<<endl;
                return;
            }
            temp = temp->next;
            while(temp){
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
            while(temp){
                i++;
                if(temp->val== v) break;
                temp = temp->next;
            }
            return i;
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
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    l.deleteNode(20);
    l.display();
    cout<<"Search data: "<<l.searchNode(15)<<endl;
}