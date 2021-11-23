#include <bits/stdc++.h>
using namespace std;

/*

There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] 
indicates that there is a flight from city fromi to city toi with 
cost pricei.

You are also given three integers src, dst, and k, return the cheapest 
price from src to dst with at most k stops. If there is no such route, 
return -1.


1. Using Disjkstra
2. Storing number of stops in the queue to check if it exceeds value of k

*/

class Solution
{
public:
    void solve(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        vector<pair<int, int>> graph[n + 1];
        int cost, u, stops;
        int ans = -1;

        for (auto x: flights)
        {
            graph[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push(make_tuple(0, src, 0));

        while (!q.empty())
        {
            tie(cost, u, stops) = q.top();
            q.pop();

            if(u==dst) ans = cost;
            if(stops > k) continue;
            
            for (auto it : graph[u])
            {
                q.push(make_tuple(it.second+cost, it.first, stops+1));
            }
        }

        cout<< ans<<endl;
    }
};

int main()
{
    vector<vector<int>> v = {{0,1,100}, {1,2,100}, {0,2,500}};
    Solution s;
    s.solve(3, v, 0, 2, 0);
}