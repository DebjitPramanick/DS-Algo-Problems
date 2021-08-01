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

    for (int i = 0; i < s.size(); i++){
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) res += s[i];

        else if (s[i] == '(') st.push(s[i]);
        
        else if (s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                char op = st.top();
                res += op;
                st.pop();
            }
            if (!st.empty()) st.pop();
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

    return res;
};

int main(){
    string res = convert("(a-b/c)*(a/k-l)");
    cout << res;
    return 0;
}
