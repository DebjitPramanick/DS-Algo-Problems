# Function to check if all subsets are filled or not
def checkSum(sumLeft, k):
 
    r = True
    for i in range(k):
        if sumLeft[i]:
            r = False
 
    return r
 
 
# Helper function for solving `k` partition problem.
# It returns true if there exist `k` subsets with the given sum
def subsetSum(S, n, sumLeft, A, k):
 
    # return true if a subset is found
    if checkSum(sumLeft, k):
        return True
 
    # base case: no items left
    if n < 0:
        return False
 
    result = False
 
    # consider current item `S[n]` and explore all possibilities
    # using backtracking
    for i in range(k):
        if not result and (sumLeft[i] - S[n]) >= 0:
 
            # mark the current element subset
            A[n] = i + 1
 
            # add the current item to the i'th subset
            sumLeft[i] = sumLeft[i] - S[n]
 
            # recur for remaining items
            result = subsetSum(S, n - 1, sumLeft, A, k)
 
            # backtrack: remove the current item from the i'th subset
            sumLeft[i] = sumLeft[i] + S[n]
 
    # return true if we get a solution
    return result
 
 
# Function for solving k–partition problem. It prints the subsets if
# set `S[0…n-1]` can be divided into `k` subsets with equal sum
def partition(S, k):
 
    # get the total number of items in `S`
    n = len(S)
 
    # base case
    if n < k:
        print("k-partition of set S is not possible")
        return
 
    # get the sum of all elements in the set
    total = sum(S)
    A = [None] * n
 
    # create a list of size `k` for each subset and initialize it
    # by their expected sum, i.e., `sum/k`
    sumLeft = [total // k] * k
 
    # return true if the sum is divisible by `k` and set `S` can
    # be divided into `k` subsets with equal sum
    result = (total % k) == 0 and subsetSum(S, n - 1, sumLeft, A, k)
 
    if not result:
        print("k-partition of set S is not possible")
        return
 
    # print all k–partitions
    for i in range(k):
        print(f"Partition {i} is", [S[j] for j in range(n) if A[j] == i + 1])
 
 
if __name__ == '__main__':
 
    # Input: a set of integers
    S = [4,3,2,3,5,2,1]
    k = int(input("Enter no. of partitions: "))
 
    partition(S, k)