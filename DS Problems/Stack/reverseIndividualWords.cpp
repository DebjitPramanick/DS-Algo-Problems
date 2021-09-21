#include <bits/stdc++.h>
using namespace std;

// Given a string str, we need to print reverse of individual words.

int main()
{
    stack<char> s;
    string str = "Hello World";
    str+=" ";
    string ans = "";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
            s.push(str[i]);
        else
        {
            string word = "";
            while (!s.empty())
            {
                word += s.top();
                s.pop();
            }
            ans += word + " ";
        }
    }
    cout << ans << endl;
}