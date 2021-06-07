# almost Sorted

Glven an array of integers, determine whether the array can be sorted in ascending order using only one of the following
operations one time.
1. Swap two elements.
2. Reverse one sub-segment.

Determine whether one, both or neither of the operations will complete the task. Output is as follows.
1. If the array Is already sorted, output yes on the first line. You do not need to output anything else.
2. Ifyou can sort this array using one single operation (from the two permitted operations) then output yes on the first line and
then:
- If elements can only be swapped, d[I] and d[r], output swap I r in the second line. [ and  are the indices of the elements
to be swapped, assuming that the array s indexed from 1 to 7.
- If elements can only be reversed, for the segment d[l... . r], output reverse I r in the second line. [ and r are the indices of
the first and last elements of the subarray to be reversed, assuming that the array is indexed from 1 to n. Here d[l. . . 7]
represents the subarray that begins at index { and ends at index r, both Inclusive.
If an array can be sorted both ways, by using either swap or reverse, choose swap.
3. If the array cannot be sorted either way, output no on the first line.

> #### Problem Link - https://www.hackerrank.com/challenges/almost-sorted/problem

## Example

> arr = [2,3,5,4]

Either swap the 4 and 5, or reverse them to sort the array. As mentioned above, swap Is preferred over reverse. Choose swap. On the first line, print yes. On the second line, print swap 3 4.

## Steps

- Step 1: Copy the real vector to another vector.
- Step 2: Sort the second vector.
- Step 3: If the second and first vectors are same, print yes.
- Step 4: Else find the l and r indices as mentioned in the problem.
- Step 5: Then copy the real vector to a new vector.
- Step 6: Now swap the elements of indeices l and r of the third vector.
- Step 7: Now if third and second vectors are same print yes and swap l r.
- Step 8: Else again copy elements of real vector to the third array.
- Step 9: Now reverse the sub vector from l index to r index.
- Step 10: After reversing if third vector is same as second vector print yes and reverse l r.
- Step 11: Else print no.
