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

    void display(){
        Node* temp = head;
        cout<<endl;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    List l;
    srand(time(NULL));
    for(int i=0;i<7;i++){
        int b = rand()%10;
        l.insert(b);
    }
    l.display();
}