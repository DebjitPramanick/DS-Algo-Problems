#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int val){
        s1.push(val);
    }

    void pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty.";
            cout<<endl;
        }
        else if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    int peek(){
        if(s1.empty() && s2.empty()){
            return -1;
        }
        else if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int top = s2.top();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return top;
        }

        return -1;
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};


class Queue2 {
    stack<int> s;

    public:

    void push(int x){
        s.push(x);
    }
 
    int pop(){
        if (s.empty()) {
            cout << "Q is empty";
            exit(0);
        }
 
        int x = s.top();
        s.pop();
 
        if (s.empty())
            return x;
 
        int item = pop();
 
        s.push(x);
 
        return item;
    }

};



int main(){
    Queue2 q;
    q.push(5);
    q.push(9);
    q.push(6);
    q.push(10);
    cout<<"Front element: "<<q.pop()<<endl;
    cout<<"Front element: "<<q.pop()<<endl;
    cout<<"Front element: "<<q.pop()<<endl;
    cout<<"Front element: "<<q.pop()<<endl;
}