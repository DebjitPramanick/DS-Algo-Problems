# Counter Game

Louise and Richard have developed a numbers game. They pick a number and check to see If it is a power of 2. If t i, they
divide it by 2. If not, they reduce it by the next lower number which is a power of 2. Whoever reduces the number to 1 wins the
game. Loulse always starts.

Given an initial value, determine who wins the game.


> #### Problem Link - https://www.hackerrank.com/challenges/encryption/problem

## Example

> n =132

It's Louise's turn first. She determines that 132 is not a power of 2. The next lower power of 2 is 128, so she subtracts that from
132 and passes 4 to Richard. 4 is a power of 2, 50 Richard divides it by 2 and passes 2 to Louise. Likewise, 2 s a power so she
divides it by 2 and reaches 1. She wins the game.

Update If they initially set counter to 1, Richard wins. Louise cannot make a move so she loses.


## Steps

- Step 1: Initialize a while loop and a counter.
- Step 2: If number is not a power of 2 find its nearest number which is power of 2.
- Step 3: Then reduce the nearest number from the actual number.
- Step 4: Else divide the number by 2.
- Step 5: When the number changes make increase or decrease the counter.
- Step 6: If counter value is 1 return "Richard" else return "Louise".