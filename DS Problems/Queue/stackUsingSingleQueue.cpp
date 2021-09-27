#include<bits/stdc++.h>
using namespace std;

class Stack{
    int N;
    queue<int> q;

    public:
    
    Stack(){
        N = 0;
    }

    void push(int x){
        int s = q.size();
        N++;
        q.push(x);
        for(int i=0;i <s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop(){
        q.pop();
        N--;
    }

    int top(){
        return q.front();
    }

    int size(){
        return N;
    }
};


int main(){
    Stack s;
    s.push(4);
    s.push(6);
    s.push(3);
    s.push(1);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}