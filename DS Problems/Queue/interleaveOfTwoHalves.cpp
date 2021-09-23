#include <bits/stdc++.h>
using namespace std;

/*
Given a queue of integers of even length, rearrange the 
elements by interleaving the first half of the queue with 
the second half of the queue.

Only a stack can be used as an auxiliary space.
*/

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

void interLeave(queue<int> &q)
{
    if (q.empty() || q.size()%2!=0)
        return;
    
    int h = q.size()/2;
    stack<int> s;

    for(int i=0;i<h;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i=0;i<h;i++){
        q.push(q.front());
        q.pop();
    }

    for(int i=0;i<h;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
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
    interLeave(q);
    display(q);
}