# Bigger Is Greater

Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.

Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:

- It must be greater than the original word
- It must be the smallest word that meets the first condition

For example, given the word , the next largest word is .

Complete the function biggerIsGreater below to create and return the new string meeting the criteria. If it is not possible, return no answer.

> #### Problem Link - https://www.hackerrank.com/challenges/bigger-is-greater/problem

## Example

String = ecdigf

Result = ecfdgi

## Steps

- Step 1: Traverse string from right to left.
- Step 2: Traverse untill you get an element lesser than previous one
- Step 3: Separate the matrix in two parts (1st array will include the - current element)
- Step 4: Find minimum but greater than current element from second arrary
- Step 5: Now take that minimum element and swap it with current element.
- Step 6: Now sort the second part of the string/array.
