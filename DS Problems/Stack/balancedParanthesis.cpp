#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else if(s[i]==')'){
            if(st.top() == '(') st.pop();
        }
        else if(s[i]=='}'){
            if(st.top() == '{') st.pop();
        }
        else{
            if(st.top() == '[') st.pop();
        }
    }

    if(!st.empty()) return false;
    return true;
}

int main(){
    bool res = isBalanced("[({})]");
    cout << res;
    return 0;
}
