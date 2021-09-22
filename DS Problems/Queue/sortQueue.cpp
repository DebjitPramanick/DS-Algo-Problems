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

void insertMinToRear(queue<int> &q, int minIndex){

    int minVal;
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();
        if (i != minIndex)
            q.push(curr);
        else
            minVal = curr;
    }
    q.push(minVal);
}

int minIdx(queue<int> &q, int s){
    int mi = -1;
    int minVal = INT_MAX;
    int n = q.size();
    for(int i=0; i<n;i++){
        int cur = q.front();
        q.pop();

        if(cur<=minVal and i<=s){
            mi = i;
            minVal = cur;
        }

        q.push(cur);
    }

    return mi;
}

void sortQueue(queue<int> &q)
{
    if (q.empty())
        return;

    for(int i=1;i<=q.size();i++){
        int minIndex = minIdx(q, q.size()-i);
        insertMinToRear(q, minIndex);
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
    sortQueue(q);
    display(q);
}