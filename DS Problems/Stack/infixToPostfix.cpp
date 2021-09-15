#include <bits/stdc++.h>
using namespace std;

class Solution
{
    stack<int> s;
    string res = "";

public:
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        return -1;
    }

    void convert(string exp)
    {
        if (exp.length() == 0)
            return;

        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] >= 'a' and exp[i] < 'z')
                res += exp[i];
            else if (exp[i] == '(')
                s.push(exp[i]);
            else if (exp[i] == ')')
            {
                while (s.top() != '(')
                {
                    res += s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.empty() and prec(s.top()) >= prec(exp[i]))
                {
                    res += s.top();
                    s.pop();
                }
                s.push(exp[i]);
            }
        }

        while (!s.empty())
        {
            res += s.top();
            s.pop();
        }

        cout << "Postfix is: " << res << endl;
    }
};

int main()
{
    Solution s;
    s.convert("a+b*(c^d-e)^(f+g*h)-i");
}