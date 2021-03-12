# Lilly's Homework

Whenever George asks Lily to hang out, she's busy doing homework. George wants to help her finish it faster, but he's In over his head! Can you help George understand Lily's homework so she can hang out with him?
Consider an array of n distinct integers, arr = [a[0], a[1],...,a[n — 1]]. George can swap any two elements of the array any number of times. An array is beautiful if the sum of |arr[i] — arr[i — 1]| among 0 < & < n is minimal.
Given the array arr, determine and return the minimum number of swaps that should be performed In order to make the array beautiful.

> #### Problem Link - https://www.hackerrank.com/challenges/lilys-homework/problem

## Example

> arr = [7,15,12,3]

One minimal array is [3, 7, 12, 15]. To get there, George performed the following swaps:

> Swap        Result
>             [7, 15, 12, 3]
> 3   7       [3,15, 12, 7]
> 7   15      (3,7, 12, 15]

It took 2 swaps to make the array beautiful. This is minimal among the choices of beautiful arrays possible.


## Steps

