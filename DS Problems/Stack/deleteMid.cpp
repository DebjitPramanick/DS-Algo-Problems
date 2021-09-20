#include<bits/stdc++.h>
using namespace std;

void display(stack<int> s){
    stack<int> temp = s;
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
}

void deleteMid(stack<int> &s){
    stack<int> q;
    int n = 0;
    while(!s.empty()){
        int t = s.top();
        n++;
        s.pop();
        q.push(t);
    }

    int i = 0;
    while(!q.empty()){
        if(i!=n/2){
            int t = q.top();
            q.pop();
            s.push(t);
        }
        else{
            q.pop();
        }
        i++;
    }
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
    deleteMid(s);
    display(s);
}