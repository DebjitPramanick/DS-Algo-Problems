#include <bits/stdc++.h>
using namespace std;

void display(queue<int> q)
{
    if (q.empty())
    {
        cout << endl;
        return;
    }
    cout << q.front() << " ";
    q.pop();
    display(q);
}


void reverseRec(queue<int> &q)
{
    if (q.empty())
        return;
    int f = q.front();
    q.pop();
    reverseRec(q);
    q.push(f);
}

void reverse(queue<int> &q)
{
    if (q.empty())
        return;
    stack<int> s;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        s.push(f);
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    int i = 0;
    while (i < 6)
    {
        int el = rand() % 100;
        cout << "Pushing: " << el << endl;
        q.push(el);
        i++;
    }
    display(q);
    reverse(q);
    display(q);
}