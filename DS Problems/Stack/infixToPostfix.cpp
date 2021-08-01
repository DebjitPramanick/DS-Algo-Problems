#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string convert(string s){
    stack<char> st;
    string res = "";

    reverse(s.begin(), s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i] = ')';
        else if(s[i]==')') s[i] = '(';
    }

    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<'z') res+=s[i];
        else if(s[i]=='(') st.push(s[i]); 
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && prec(st.top()) > prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
};

int main(){
    string res = convert("(a-b/c)*(a/k-l)");
    cout << res;
    return 0;
}
