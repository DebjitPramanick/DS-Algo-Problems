#include <bits/stdc++.h>
using namespace std;

/*
You are given an array, A, of n elements. You have to remove exactly
n/2 elements from array A and add it to another array B(initially empty)

Find the max and min values of differences between these two arrays.
We define the difference between these two arrays as:
Σabs(A[i]-B[i])
*/

bool cmp(vector<int> a, vector<int> b){
    double m = (double) a[1]/a[0];
    double n = (double) b[1]/b[0];
    // We will find price of uint weight

    return m>n;
}

int main(){
    vector<int> nums = {5, 2, 4, 7};
    sort(nums.begin(), nums.end());
    int n = nums.size();

    long long mn= 0, mx = 0;

    for(int i=0;i<n/2;i++){
        mx+=(nums[i+n/2] - nums[i]);
        mn+=(nums[2*i+1] - nums[2*i]);
    }

    cout<<"Min and max answers: "<<mn<<", "<<mx<<endl;

}