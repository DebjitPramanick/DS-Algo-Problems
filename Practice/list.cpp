#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

class List{
    Node* head = NULL;

    public:
    void insert(int v){
        if(!head){
            head = new Node(v);
        }
        else{
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = new Node(v);
        }
    }

    int count(){
        Node* temp = head;
        int c = 0;
        while (temp) {
            temp = temp->next;
            c++;
        }

        return c;
    }

    void display(){
        Node* temp = head;
        cout<<endl;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    Node* search(int k){
        Node* temp = head;
        while(temp){
            if(temp->val == k) return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void reverse(){
        Node *temp = head, *p, *q = NULL;
        while(temp){
            p = temp->next;
            temp->next = q;
            q = temp;
            temp = p;
        }
        head = q;
    }

};

int main(){
    List l;
    srand(time(NULL));
    for(int i=1;i<=7;i++){
        int b = rand()%10;
        l.insert(i*6);
    }
    l.display();
    l.reverse();
    l.display();
}