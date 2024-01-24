#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

void convert(string s){
    stack<char> st;
    string res = "";

    reverse(s.begin(), s.end());

    for(int i=0;i<s.length();i++){
        if(s[i] == '(') {
            s[i] = ')';
            i++;
        }
        else if(s[i] == ')') {
            s[i] = '(';
            i++;
        };
    }

    s = '('+s+')';

    for (int i = 0; i < s.size(); i++){
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) res += s[i];
        else if(s[i] == '(') st.push('(');
        else if(s[i] == ')') {
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() and prec(s[i])<=prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    reverse(res.begin(), res.end());

    cout<<"Prefix expression is: "<<res<<endl;

    
};

int main(){
    convert("(a-b/c)*(a/k-l)");
    return 0;
}
