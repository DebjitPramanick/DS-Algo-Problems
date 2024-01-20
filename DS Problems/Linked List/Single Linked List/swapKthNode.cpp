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
    Node *head = new Node();
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

        void swapKthNodes(int n){
            if(!head || !head->next) {
                cout<<"List is empty."<<endl;
                return;
            }
            
            Node *temp = head;
            Node *p1 = head, *p2 = head, *p1_prev = NULL, *p2_prev = NULL;
            int i = 0;
            while(temp->next){
                i++;
                temp = temp->next;
            }

            if (2 * n - 1 == i) return;

            for(int j=1;j<n;j++){
                p1_prev = p1;
                p1 = p1->next;
            }

            for(int j=1;j<=(i-n+1);j++){
                p2_prev = p2;
                p2 = p2->next;
            }

            if(p1_prev) p1_prev->next = p2;
            if(p2_prev) p2_prev->next = p1;
            
            
            Node *tmp = p1->next;
            p1->next = p2->next;
            p2->next = tmp;

            if (n == 1) head = p2;
            if (n == i) head = p1;
            
        }

};

int main(){
    LinkedList l;
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    l.swapKthNodes(0);
    l.display();
}
