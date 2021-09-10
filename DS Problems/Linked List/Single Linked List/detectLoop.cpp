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

        void createLoop(){
            if(!head) return;
            Node *temp = head, *ext = head;
            while(temp->next)
                temp = temp->next;
            
            int i = 0;
            while(i<=2){
                i++;
                ext = ext->next;
            }
            temp->next = ext;
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


        void detectLoop1(){ // Hashmap approach
            if(!head) {
                cout<<"List is empty"<<endl;
                return;
            }
            Node *temp = head;
            map<int,bool> mp;
            while(temp){
                if(mp[temp->val]) {
                    cout<<"There is a loop in list."<<endl;
                    return;
                }
                mp[temp->val] = true;
                temp = temp->next;
            }
            cout<<"There is no loop in list."<<endl;
        }

        void detectLoop2(){ // Hashmap approach
            if(!head) {
                cout<<"List is empty"<<endl;
                return;
            }
            Node *fast = head, *slow = head;
            // fast = fast->next->next;
            // slow = slow->next;

            while(slow and fast and fast->next){
                fast = fast->next->next;
                slow = slow->next;

                if(fast == slow) {
                    cout<<"There is a loop in list."<<endl;
                    return;
                }
            }
            cout<<"There is no loop in list."<<endl;
        }

};

int main(){
    LinkedList l;
    for(int i=0;i<5;i++){
        l.insertNode(5*(i+1));
    }

    l.display();
    // l.createLoop();
    l.detectLoop1();
    l.detectLoop2();
}

