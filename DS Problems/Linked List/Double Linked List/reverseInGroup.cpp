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

        Node* reverseUtil(Node *hd, int k){
            if(!hd) return NULL;

            hd->prev = NULL;
            Node *temp, *cur = hd, *nh;
            int count = 0;
            while(cur and count<k){
                nh = cur;
                temp = cur->prev;
                cur->prev = cur->next;
                cur->next = temp;
                cur = cur->prev;
                count++;
            }

            if(count>=k){
                Node *rest = reverseUtil(cur, k);
                hd->next = rest;
                if(rest) rest->prev = head;
            }

            return nh;
        }

        void reverseInGroup(int k){
            if(!head || !head->next) return;

            head = reverseUtil(head, k);
        }

};

int main(){
    LinkedList l;
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    l.reverseInGroup(2);
    l.display();
}

