#include<bits/stdc++.h>
using namespace std;

// Given a stack of integers, sort it in ascending order using another temporary stack.

void display(stack<int> s){
    stack<int> temp = s;
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
}

void insert(stack<int> &s, int el){
    if(s.empty()){
        s.push(el);
        return;
    }
    if(s.top()>el){
        int t = s.top();
        s.pop();
        insert(s, el);
        s.push(t);
    }
    else{
        s.push(el);
    }
}

void sort(stack<int> &s){
    if(s.empty()) return;
    int t = s.top();
    s.pop();
    sort(s);
    insert(s, t);
}

int main(){
    stack<int> s;
    int i = 1;
    while(i<6) {
        int v = rand()%100;
        cout<<"Pushing: "<<v<<endl;
        s.push(v);
        i++;
    }
    sort(s);
    display(s);
}