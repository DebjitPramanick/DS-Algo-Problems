#include <bits/stdc++.h>
using namespace std;

// Given an array of n integers and q queries,
// print the number of next greater elements to
// the right of the given index element.

vector<int> solve(int a[], int n)
{
    stack<int> st;
    vector<int> nxt;

    st.push(n-1);
    nxt.push_back(0);

    for (int i = n-2; i >= 0; i--)
    {
        while (!st.empty() and a[i]>=a[st.top()]){
            st.pop();
        }

        if (st.empty()) nxt.push_back(0);
        else nxt.push_back(nxt[n - st.top() - 1] + 1);

        st.push(i);
    }

    reverse(nxt.begin(), nxt.end());
    return nxt;
};

int main()
{
    int a[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> nxt = solve(a, n);

    // query 1 answered
    cout << nxt[3] << endl;
 
    // query 2 answered
    cout << nxt[6] << endl;
 
    // query 3 answered
    cout << nxt[1] << endl;
}
