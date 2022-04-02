#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next, *prev;
    Node(int v){
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class List{
    Node* head = NULL;

    public:

    Node* getHead(){
        return head;
    }

    void insert(int v){
        if(!head){
            head = new Node(v);
        }
        else{
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = new Node(v);
            temp->next->prev = temp;
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

    void rotate(int k){
        int n = count();
        Node* temp = head;
        int i;
        for(i=1;i<=k;i++){
            temp = temp->next;
        }
        Node* nh = temp;
        while(temp && temp->next){
            temp=temp->next;
        }

        temp->next = head;
        head->prev = temp;
        nh->prev->next = NULL;
        nh->prev = NULL;
        head = nh;
    }

};

int main(){
    List l;
    srand(time(NULL));
    for(int i=1;i<=7;i++){
        int b = rand()%10;
        l.insert(i*2);
    }

    l.display();
    l.rotate(2);
    l.display();
}