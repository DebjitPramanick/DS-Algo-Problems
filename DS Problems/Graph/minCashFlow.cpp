#include<iostream>
using namespace std;
#define N 3

/*
Given a number of friends who have to give or take some amount of 
money from one another. Design an algorithm by which the total cash 
flow among all the friends is minimized.

Do following for every person Pi where i is from 0 to n-1.  

1. Compute the net amount for every person. The net amount for person ‘i’ can be 
   computed by subtracting sum of all debts from sum of all credits.
2. Find the two persons that are maximum creditor and maximum debtor. Let the 
   maximum amount to be credited from maximum creditor be maxCredit and maximum amount 
   to be debited from maximum debtor be maxDebit. Let the maximum debtor be Pd 
   and maximum creditor be Pc.
3. Find the minimum of maxDebit and maxCredit. Let minimum of two be x. Debit 
   ‘x’ from Pd and credit this amount to Pc
4. If x is equal to maxCredit, then remove Pc from set of persons and recur 
   for remaining (n-1) persons.
5. If x is equal to maxDebit, then remove Pd from set of persons and recur 
   for remaining (n-1) persons.
*/

int getMin(int arr[])
{
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}
 
// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}


void minCashFlowRec(int amount[]){
    int mxC = getMax(amount), mxD = getMin(amount);
    if(amount[mxC]==0 and amount[mxD]==0) return;

    int x = min(-amount[mxD], amount[mxC]);
    amount[mxC] -= x;
    amount[mxD] += x;
    cout << "Person " << mxD << " pays " << x
         << " to " << "Person " << mxC << endl;
    minCashFlowRec(amount);
}

void minCashFlow(int graph[][N]){
    int amount[N] = {0};
    for(int p=0;p<N;p++){
        for(int i=0;i<N;i++) amount[p] += (graph[i][p] - graph[p][i]);
    }

    minCashFlowRec(amount);
}

int main()
{
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
    // Print the solution
    minCashFlow(graph);
    return 0;
}