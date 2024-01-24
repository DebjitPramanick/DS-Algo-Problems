#include <bits/stdc++.h>
using namespace std;

// Shuffle a given array using Fisher–Yates shuffle Algorithm

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

void shuffle(int a[], int n){
    int b[n];
    copy(a, b, n);

    // Use a different seed value so that
    // we don't get same result each time
    // we run this program
    srand (time(NULL));

    for(int i=n-1;i>=0;i--){ // Fisher and Yates' method
        int j = rand()%(i+1);
        swap(b[i], b[j]);
    }

    display(b, n);

}

int main()
{
    int a[] = {7, 3, 5, 4, 5, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    shuffle(a, n);
}
