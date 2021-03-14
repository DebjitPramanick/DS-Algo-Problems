# Larry's Array

Larry has been given a permutation of a sequence of natural numbers incrementing from 1 as an array. He must determine whether the array can be sorted using the following operation any number of times:
* Choose any 3 consecutive indices and rotate their elements in such a way that ABC —> BCA —> CAB —> ABC.


> #### Problem Link - https://www.hackerrank.com/challenges/larrys-array/problem

## Example

> A = {1,6,5,2,4,3}:

A                 Rotate
[1,6,5,2,4,3]     [6,5,2]
[1,5,2,6,4,3]     [5,2,6]
[1,2,6,5,4,3]     [5,4,3]
[1,2,6,3,5,4]     [6,3,5]
[1,2,3,5,6,4]     [5,6,4]
[1,2,3,4,5,6]

ves

On a new line for each test case, print YES if A can be fully sorted. Otherwise, print NO.

## Steps

- Step 1: Check how many inversions will take place.
- Step 2: For counting number of inversions check how many greater integers are present just at the left side of a particular element.
- Step 3: Count those number of elements for each element.
- Step 4: Now if total count is divisible by 2 return YES else return NO.
