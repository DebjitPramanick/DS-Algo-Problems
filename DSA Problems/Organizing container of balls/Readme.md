# Organizing Containers of Balls

David has several containers, each with a number of balls in it. He has just enough containers to sort each type of ball he has into its own container. David wants to sort the balls using his sort method.

> #### Problem Link - https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

## Example

Suppose n = 3

Containers:
X0	X1	X2

Ball Types:
B0	B1	B2


Matrix will be:
1		2		1
2		1		2
3		1		1

[col = BALL TYPE, row = CONTAINER TYPE]

## Steps

Step 1: Create two arrays (boxes and types)
Step 2: Store sums of row and column in two arrays
Step 3: Compare each elemnent of two arrays
Step 4: Now sort two arrays.
Step 5: If mismatch does not occur print "POSSIBLE"
Step 6: Else print "IMPOSSIBLE"
