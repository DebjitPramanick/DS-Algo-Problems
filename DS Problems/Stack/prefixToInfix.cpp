#include <bits/stdc++.h>
using namespace std;

class Solution
{
    stack<string> s;

public:

    void convert(string exp)
    {
        if (exp.length() == 0)
            return;
        reverse(exp.begin(), exp.end());

        for (int i = 0; i < exp.length(); i++)
        {
            if(exp[i]>='a' && exp[i]<='z'){
                string op(1, exp[i]);
                s.push(op);
            }
            else{
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();
                string ans = "("+op1+exp[i]+op2+")";
                s.push(ans);
            }
        }

        cout << "Infix is: " << s.top() << endl;
    }
};

int main()
{
    Solution s;
    s.convert("*-a/bc-/akl");
}