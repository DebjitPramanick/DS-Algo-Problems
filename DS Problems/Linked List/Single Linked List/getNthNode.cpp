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

        void deleteNode(int v){
            if(!head){
                cout<<"List is empty."<<endl;
                return;
            }
            Node *temp = head;
            if(temp->val== v){
                head = temp->next;
                temp->next = NULL;
                delete(temp);
                cout<<"List item deleted."<<endl;
                return;
            }
            Node *prev = temp;
            temp = temp->next;
            while(temp){
                if(temp->val == v){
                    prev->next = temp->next;
                    temp->next = NULL;
                    delete(temp);
                    cout<<"List item deleted."<<endl;
                    return;
                }
                prev = temp;
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

        int getNthNode(int pos){
            if(!head) return -1;
            Node *temp = head;
            int i = 0;
            while(temp){
                i++;
                if(i==pos) return temp->val;
                temp = temp->next;
            }
            return -1;
        }

};

int main(){
    LinkedList l;
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    l.deleteNode(15);
    l.deleteNode(25);
    l.display();
    l.insertNode(34);
    l.display();
    cout<<"Item is: "<<l.searchNode(34)<<"th element."<<endl;
    cout<<"3rd node is: "<<l.getNthNode(3)<<endl;
}

