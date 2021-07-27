#include<bits/stdc++.h>
using namespace std;

void display(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void insert(stack<int> &s, int el){
    if(s.empty()){
        s.push(el);
        return;
    }
    int top = s.top();
    s.pop();
    insert(s, el);
    s.push(top);
}

void reverse(stack<int> &s){
    if(s.empty()) return;
    int el = s.top();
    s.pop();
    reverse(s);
    insert(s, el);
}

int main(){
    stack<int> s;
    int i = 1;
    while(i<10) {
        int v = rand()%100;
        cout<<"Pushing: "<<v<<endl;
        s.push(v);
        i++;
    }
    reverse(s);
    display(s);
}