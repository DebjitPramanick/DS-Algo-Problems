#include <bits/stdc++.h>
using namespace std;

/*
There are a total of numCourses courses you have to take,
labeled from 0 to numCourses - 1. You are given an array
prerequisites where prerequisites[i] = [ai, bi] indicates
that you must take course bi first if you want to take
course ai.

For example, the pair [0, 1], indicates that to take course
0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return
false.
*/

class Solution
{
private:
    vector<vector<int>> prerequisites;
    int numCourses = 0;

public:
    Solution(vector<vector<int>> _v, int _num)
    {
        prerequisites = _v;
        numCourses = _num;
    }

    void solve()
    {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for (auto x : prerequisites)
        {
            adj[x[0]].push_back(x[1]);
        }

        for(int i=0;i<numCourses;i++){
            for(auto x: adj[i]){
                indegree[x]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(cnt == numCourses)  cout<<"You can finish all the courses.";
        else cout<<"You cannot finish all the courses.";
    }
};

int main()
{
    vector<vector<int>> pre = {
        {1, 0},
        {0, 1}};
    Solution s(pre, 2);
    s.solve();
}