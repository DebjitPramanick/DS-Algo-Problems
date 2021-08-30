#include <bits/stdc++.h>
using namespace std;

// Given an array of size n where all elements are 
// distinct and in range from 0 to n-1, change contents 
// of arr[] so that arr[i] = j is changed to arr[j] = i. 


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


void rearrangeArray(int a[], int n){
    int b[n], temp[n];
    copy(a, b, n);
    copy(b, temp, n); // Copy main array to temp array

    for(int i=0;i<n;i++){
        int idx = temp[i];
        b[idx] = i;
    }

    display(b, n);
}

void rearrangeArraySecond(int a[], int n){
    int b[n], temp[n];
    copy(a, b, n);

    for(int i=0;i<n;i++) b[i]++; // Increment all values by 1, so that all elements can be made negative to mark them as visited
    for(int i=0;i<n;i++) {
        if(b[i] > 0) {
            int val = -(i+1); // The next value is determine using current index
            int i = b[i]-1; // The next index is determined using current value

            while(b[i]>0){ // While all elements in cycle are not processed
                int new_i = b[i]-1; // Store value at index as it is going to be used as next index
                b[i] = val; // Update array

                // Update value and index
                val = -(i+1);
                i = new_i;
            }
        }
    }

    // Change sign and values of arr[] to get the original
    // values back, i.e., values in range from 0 to n-1
    for (int i = 0; i < n; i++) b[i] = (-b[i]) - 1;

    display(b, n);
}

int main()
{
    int a[] = {1, 3, 0, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    rearrangeArray(a, n);
}
