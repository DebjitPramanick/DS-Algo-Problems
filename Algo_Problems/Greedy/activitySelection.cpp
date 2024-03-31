#include <bits/stdc++.h>
using namespace std;

/*
You are given n activities with their start and end time.
Select the max number of activities that can be performed 
by a single person, assuming that a person can only work
on a single activity at a time.
*/

int main(){
    vector<pair<int,int>> tasks;
    tasks.push_back({10, 20});
    tasks.push_back({12, 15});
    tasks.push_back({20, 30});

    int n = tasks.size();

    sort(tasks.begin(), tasks.end(), [&](pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    });

    int canTake = 1;
    int end = tasks[0].second; // Taking the first task first
    
    
    // Then going for next tasks which can be completed
    for(int i=1;i<n;i++){
        if(tasks[i].first >= end){
            canTake++;
            end = tasks[i].second;
        }
    }

    cout<<"Max activities: "<<canTake<<endl;

}