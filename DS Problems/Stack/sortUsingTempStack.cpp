#include<bits/stdc++.h>
using namespace std;

// Given a stack of integers, sort it in ascending order using another temporary stack.

/*
Dry Run:

input: [34, 3, 31, 98, 92, 23]

Element taken out: 23
input: [34, 3, 31, 98, 92]
tmpStack: [23]

Element taken out: 92
input: [34, 3, 31, 98]
tmpStack: [23, 92]

Element taken out: 98
input: [34, 3, 31]
tmpStack: [23, 92, 98]

Element taken out: 31
input: [34, 3, 98, 92]
tmpStack: [23, 31]

Element taken out: 92
input: [34, 3, 98]
tmpStack: [23, 31, 92]

Element taken out: 98
input: [34, 3]
tmpStack: [23, 31, 92, 98]

Element taken out: 3
input: [34, 98, 92, 31, 23]
tmpStack: [3]

Element taken out: 23
input: [34, 98, 92, 31]
tmpStack: [3, 23]

Element taken out: 31
input: [34, 98, 92]
tmpStack: [3, 23, 31]

Element taken out: 92
input: [34, 98]
tmpStack: [3, 23, 31, 92]

Element taken out: 98
input: [34]
tmpStack: [3, 23, 31, 92, 98]

Element taken out: 34
input: [98, 92]
tmpStack: [3, 23, 31, 34]

Element taken out: 92
input: [98]
tmpStack: [3, 23, 31, 34, 92]

Element taken out: 98
input: []
tmpStack: [3, 23, 31, 34, 92, 98]

final sorted list: [3, 23, 31, 34, 92, 98]

*/

void display(stack<int> s){
    stack<int> temp = s;
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
}

void sort(stack<int> &s){
    stack<int> temp;
    while(!s.empty()){
        int t = s.top();
        s.pop();
        while(!temp.empty() and temp.top() > t){ // Push to input stack untill top of temp < top of input
            s.push(temp.top());
            temp.pop();
        }
        temp.push(t);
    }

    s = temp;
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