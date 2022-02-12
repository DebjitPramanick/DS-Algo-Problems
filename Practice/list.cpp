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

    Node* partition(Node *h, Node* end, Node** nh, Node** ne){
        Node* pivot = end;
        Node *tail = end, *cur = h, *prev = NULL;

        while(cur!=pivot){
            if(cur->val < pivot->val){
                if(!(*nh)) (*nh) = cur;
                prev = cur;
                cur = cur->next;
            }
            else{
                if(prev) prev->next = cur->next;
                Node* tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if(!(*nh)) (*nh) = pivot;
        (*ne) = tail;
        return pivot;
    }

    Node *getTail(Node *h){
        while(h && h->next) h = h->next;
        return h;
    }

    Node* qs(Node *h, Node* end){
        if(!h || h == end) return h;
        Node *nh = NULL, *ne = NULL;
        Node* pivot = partition(h, end, &nh, &ne);

        if(nh!=pivot){
            Node* temp = nh;
            while(temp->next != pivot) temp = temp->next;
            temp->next = NULL;
            nh = qs(nh, temp);
            temp = getTail(nh);
            temp->next = pivot;
        }

        pivot->next = qs(pivot->next, ne);
        return nh;
    }

    void sort(){
        if(!head) return;
        Node **hRef = &head;
        (*hRef) = qs(*hRef, getTail(head));
    }

};

int main(){
    List l;
    // srand(time(NULL));
    // for(int i=1;i<=7;i++){
    //     int b = rand()%10;
    //     l.insert(b);
    // }

    l.insert(5);
    l.insert(3);
    l.insert(2);
    l.insert(6);
    l.insert(4);
    l.insert(7);
    l.display();
    l.sort();
    l.display();
}