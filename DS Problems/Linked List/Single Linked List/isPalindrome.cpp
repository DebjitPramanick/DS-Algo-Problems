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

        void isPalindrome(){
            if(!head) {
                cout<<"List is empty."<<endl;
                return;
            }
            Node *temp = head;
            stack<int> s;
            while(temp){
                s.push(temp->val);
                temp = temp->next;
            }

            temp = head;

            while(temp){
                if(s.top() != temp->val){
                    cout<<"List is not palindrome."<<endl;
                    return;
                }
                s.pop();
                temp = temp->next;
            }

            cout<<"List is palindrome."<<endl;
        }

};

int main(){
    LinkedList l;
    l.insertNode(4);
    l.insertNode(5);
    l.insertNode(2);
    l.insertNode(5);
    l.insertNode(6);

    l.display();
    l.isPalindrome();
}

