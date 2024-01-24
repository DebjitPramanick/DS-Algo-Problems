#include <bits/stdc++.h>
using namespace std;

// Given an array and a number k where k is smaller
// than the size of the array, we need to find the k’th
// smallest element in the given array. It is given that
// all array elements are distinct.

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void copy(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

int findMedian(int arr[], int n)
{
    sort(arr, arr + n); // Sort the array
    return arr[n / 2];  // Return middle element
}

int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(arr[i], arr[r]);

    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int findKthElement(int a[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1; // Number of elements in arr[l..r]

        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i, median[(n + 4) / 5]; // There will be floor((n+4)/5) groups;
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(a + l + i * 5, 5);
        if (i * 5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(a + l + i * 5, n % 5);
            i++;
        }

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1) ? median[i - 1] : findKthElement(median, 0, i - 1, i / 2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(a, l, r, medOfMed);

        // If position is same as k
        if (pos - l == k - 1)
            return a[pos];
        if (pos - l > k - 1) // If position is more, recur for left
            return findKthElement(a, l, pos - 1, k);

        // Else recur for right subarray
        return findKthElement(a, pos + 1, r, k - pos + l - 1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

int main()
{
    int a[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(a) / sizeof(a[0]);
    int b[n];
    copy(a, b, n);
    int ans = findKthElement(b, 0, n - 1, 3);
    cout << endl
         << ans << endl;
}
