#include <bits/stdc++.h>
using namespace std;

// Find element in sorted rotated array


/*

For alt solution:

Using binary search to compare the mid value with the 
target value. If the mid value equals the target value, 
then output the mid index. If the mid value is greater 
than the start value, then we need to see if the array 
has been pivoted, and adjust start and end according the 
comparison. Similarly, if the mid value is smaller than 
the end value, then, based on pivoting, we adjust the 
start and end value accordingly.

*/

int binarySearch(int a[], int start, int end, int key)
{
    int s = start;
    int e = end;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int findMinIdx(int a[], int n)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int nxt = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (a[mid] >= a[nxt] and a[mid] >= a[prev])
        {
            return mid + 1;
        }
        else if (a[s] <= a[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int findEl(int a[], int n, int key)
{
    int minIdx = findMinIdx(a, n);
    int lArr = binarySearch(a, 0, minIdx - 1, key);
    int rArr = binarySearch(a, minIdx, n, key);

    if (lArr != -1)
        return lArr;
    else if (rArr != -1)
        return rArr;
    return -1;
}

int altSolution(vector<int>& nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = 0;
    while (start <= end)
    {
        mid = end + (start - end) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[start] <= nums[mid])
        {
            if (target >= nums[start] && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        if (nums[end] >= nums[mid])
        {
            if (target <= nums[end] && target > nums[mid])
            {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int a[8] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int res, s;
    cout << "Enter element to search: ";
    cin >> s;
    res = findEl(a, n, s);
    if (res != -1)
        cout << "Element found at: " << res;
    else
        cout << "Element not found.";
}