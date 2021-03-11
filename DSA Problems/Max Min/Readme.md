# Max Min
 
You will be given a list of Integers, arr, and a single Integer k. You must create an array of length k from elements of arr such that Its unfairness is minimized. Call that array arr”. Unfairness of an array Is calculated as
 
> maz(arr') — min(arr')
 
Where:
- max denotes the largest integer in arr’.
- min denotes the smallest integer in arr’ .
 
 
> #### Problem Link - https://www.hackerrank.com/challenges/angry-children/problem
 
## Example
 
> arr = [1,4,7,2]
> k=2
 
Pick any two elements, say arr’ = [4,7].
 
unfairness = maz(4,7) — min(4,7) =7 -4 =3
 
Testing for all pairs, the solution [1, 2] provides the minimum unfairness.
Note: Integers In arr may not be unique.
 
 
## Steps
 
- Step 1: Sort the array.
- Step 2: Get the difference of elements after a gap of k elements
- Step 3: Store those differences in an array
- Step 4: Return the minimum element of that array
