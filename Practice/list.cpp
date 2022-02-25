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

    void swap(int k){
        if(!head) return;
        int c = 0;
        Node *first = head, *last = head, *temp = head, *pf = NULL, *pl = NULL;
        while(temp){
            c++;
            temp = temp->next;
        }
        while(last->next) last = last->next;
        for(int i=1;i<k;i++){
            pf = first;
            first = first->next;
        }

        for(int i=c;i>c-k+1;i--){
            pl = last;
            last = last->prev;
        }

        if(!pf && !pl){
            last->next = first->next;
            first->prev = last->prev;
            first->next = NULL;
            last->prev = NULL;
        }
        else if(!pf){
            last->next = first->next;
            first->prev = last->prev;
            first->next = pl;
            last->prev->next = first;
            last->prev = NULL;
            pl->prev = first;
        }

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
    l.swap(1);
    l.display();
}