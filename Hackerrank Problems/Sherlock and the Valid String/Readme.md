# Sherlock and the Valid String

Sherlock considers a string to be valid if all characters of the string appear the same number of times. Itis also valid if he can remove just 1 character at 1 index in the string, and the
remaining characters will occur the same number of times. Given a string s, determine if it is valid. If so, return YES, otherwise return NO.


> #### Problem Link - https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

## Example

> s = abc

This is a valid string because frequenciesare {a : 1,b: 1,c: 1}.

> s = abce

This is a valid string because we can remove one ¢ and have 1 of each character in the remaining string.

> s = abccc

This string is not valid as we can only remove 1 occurrence of ¢. That leaves character frequencies of {a : 1,b: 1,c: 2}.

## Steps

- Step 1: Create an array which contains frequency of each character
- Step 2: Find max freq and min freq
- Step 3: If max frequency and min frequency are equal return "YES"
- Step 4: Else find how many characters have max and min freq
- Step 5: If difference of max and min frequency is 1 and min frequency and number of characters having min freq both are 1 return "YES"
- Step 6: Else if number of characters having min freq or number of characters having max freq is 1 return "YES"
