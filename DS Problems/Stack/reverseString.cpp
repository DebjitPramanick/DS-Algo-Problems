#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<string> s;
    string str = "Debjit is good";

    int l = str.length();

    for(int i=0;i<l;i++){
        string word = "";
        while(str[i]!=' ' && i<l){
            word+=str[i];
            i++;
        }
        s.push(word+" ");
    }

    while(!s.empty()){
        string c = s.top();
        s.pop();
        cout<<c;
    }
}